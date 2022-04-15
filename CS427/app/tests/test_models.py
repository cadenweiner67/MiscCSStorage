#Caden Weiner
#This file contains tests for the data in models and hashing
from datetime import datetime, timedelta
import unittest
from app import app, db
from app.models import User
from app.hashing import *
class UserModelCase(unittest.TestCase):
    #create tests for database. 
    def setUp(self):
        app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite://'
        db.create_all()
    #removes db at the end
    def tearDown(self):
        db.session.remove()
        db.drop_all()
    #testing step, all steps start with hash
    def test_password_hashing(self):
        u = User(firstname="Lycoris", lastname="Raidata", phone="6618775655", password_plaintext='Rousey13!Rousey13!Rousey13!', lockout_date = datetime.utcnow(), salt = make_salt())
        u.my_hash = my_hash(shake_salt("Rousey13!Rousey13!Rousey13!",u.salt))
        self.assertTrue(check_my_hash("Rousey13!Rousey13!Rousey13!",u.my_hash ,u))
        self.assertFalse(check_my_hash("rousey13!Rousey13!Rousey13!",u.my_hash ,u))
        u.set_password('Rousey13!Rousey13!Rousey13!')
        
        
        self.assertFalse(u.check_password('Rousey13!Rousey13!Rousey13!!!'))
        self.assertTrue(u.check_password('Rousey13!Rousey13!Rousey13!'))
        self.assertEqual(u.password_plaintext, 'Rousey13!Rousey13!Rousey13!')
        self.assertNotEqual(u.password_hash, 'Rousey13!Rousey13!Rousey13!')
