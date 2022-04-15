#Caden Weiner
#This file contains the routes for the webapp

from __future__ import print_function
import sys
from datetime import datetime
from flask import render_template, flash, redirect, url_for, request
from flask_sqlalchemy import sqlalchemy
from flask_login import current_user, login_user, logout_user, login_required
from app.hashing import * 
from app import app,db
from threading import Timer
from app.forms import RegistrationForm, LoginForm
from app.models import User
import re
@app.before_first_request
def initDB(*args, **kwargs):
    db.create_all()
    

@app.route('/', methods=['GET', 'POST'])
@app.route('/login', methods=['GET', 'POST'])
def login(): 
    if current_user.is_authenticated:
        return redirect(url_for('secret_page'))
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.username.data).first()
        if user is None:
            flash('Invalid username')
            return redirect(url_for('login'))
        else: 
            if user.failed_attempts == 3: 
                flash('Please continue waiting to log in, your lockout time left is 60 seconds')
                timeout = Timer(60.0, refresh_attempts(user))
                flash('Your attempts have refreshed')
                
            if not user.check_password(form.password.data) or not check_my_hash(form.password.data, user.my_hash, user): 
                flash('Invalid username or password')
                flash('{}'.format(check_my_hash(form.password.data, user.my_hash, user)))
                user.failed_attempts += 1
                flash('{} failed attempts'.format(user.failed_attempts))
                if user.failed_attempts == 3: # that was the third failed attempt, they are now locked out
                    user.lockout_date = datetime.utcnow()
                    flash("Locked out for 1 minute")
                db.session.commit()
                return redirect(url_for('login'))
        login_user(user, remember=form.remember_me.data)
        return redirect(url_for('secret_page'))
    return render_template('login.html', title='Sign In', form=form)



@app.route('/register', methods=['GET', 'POST'])
def register(): 
    form = RegistrationForm()
    if form.validate_on_submit():
        # by checking that it is not all upper and not all lower, we can verify that there is at least one lowercase and one uppercase
        # enforces a password size of at least 20
        # any statement to check if there exists a digit in any of the characters
        regex = re.compile('[@_!#$%^&*()<>?/\|}{~:]') # here is a list of special characters to check if they are
        if not (not regex.search(form.password.data) == None and any(c.isdigit() for c in form.password.data) and len(form.password.data) >= 20 and len(form.password.data) <= 60 and not form.password.data.isupper() and not form.password.data.islower()): 
            flash('Password needs to have a special character, be between 20 and 60 characters, lowercase, capital and number!')
        else: 
            # we include plaintext password in here for testing purposes 
            user = User(salt=make_salt() ,username=form.username.data, phone=form.phone.data, firstname=form.firstname.data,lastname=form.lastname.data, password_plaintext = form.password.data)
            user.my_hash = my_hash(shake_salt(form.password.data, user.salt))
            user.set_password(form.password.data)
            db.session.add(user)
            db.session.commit()
            flash('Congratulations, you are now a registered user!')
            return redirect(url_for('secret_page'))
        
    return render_template('register.html', title='Register', form=form)


@app.route('/logout', methods=['GET', 'POST'])
@login_required
def logout():
    logout_user()
    return redirect(url_for('secret_page'))


@app.route('/secret_page', methods=['GET', 'POST'])
@login_required
def secret_page():
    if current_user is not None: 
        return render_template('secret_page.html', secret_user=current_user)
    else: # this will handle cases of someone breaching login required without logging in
        flash('You not have access to this page')
        return redirect(url_for('login'))
