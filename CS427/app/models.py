#Caden Weiner
#This file contains the models for the user datastructure for logins

from datetime import datetime

from app import db, login
from flask_login import UserMixin
from werkzeug.security import generate_password_hash, check_password_hash



@login.user_loader
def load_user(id):
    return User.query.get(int(id))

class User(UserMixin, db.Model): #default user is a customer
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), index=True, unique=True)
    password_hash = db.Column(db.String(256)) # hash length is already set by the algorithm
    firstname = db.Column(db.String(100))
    lastname = db.Column(db.String(100))
    email = db.Column(db.String(120), index=True, unique=True)
    last_seen = db.Column(db.DateTime, default=datetime.utcnow)
    #####################################
    phone = db.Column(db.String(1))
    lockout_date = db.Column(db.DateTime, default=datetime.utcnow)
    failed_attempts = db.Column(db.Integer, default=0) # if failed attempts reaches three set the lockout time. That way later checks see they have three strikes and the previous wait time. 
    password_plaintext = db.Column(db.String(128))
    ######################################
    salt = db.Column(db.String(32))
    my_hash = db.Column(db.String(512)) # it was being weird and truncating it initially but I fixed it
    #this function can take salt parameters.
    # maybe generate a variable sized salt? 
    def set_password(self, password):
        self.password_hash = generate_password_hash(password)

    def check_password(self, password):
        return check_password_hash(self.password_hash, password)
    
    def __repr__(self):
        return '{}-{}'.format(self.id,self.username)
