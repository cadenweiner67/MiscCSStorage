#Caden Weiner
#This file contains the helperfunctions for hashing
from datetime import datetime
from math import * 
import secrets 



def refresh_attempts(user): 
    user.failed_attempts = 0

def my_hash(password): 
    g = 41
    hash=0
    for c in password: 
        hash = g*hash + ord(c)
    return str(hash)

def check_my_hash(password, hash, user): 
    #print(user.salt)
    myhash = my_hash(shake_salt(password, user.salt))
    #print(myhash,"==",hash)
    if hash == myhash: 
        return True
    else: 
        return False


def make_salt(): 
    # salt = ...
    salt = secrets.token_hex(nbytes=16)
    return salt

def shake_salt(password, salt): # we know password portion is at least 20 chars
    salty = salt[0:10] + password[8:15] + salt[11:21] + password[16::] + salt[22:32] + password[0:7]
    #print('shaking', salty)
    return salty