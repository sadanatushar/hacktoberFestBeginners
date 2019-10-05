from flask import Flask, jsonify
import json

app = Flask(__name__)

@app.route('/')
def hello():
    return "hell"


@app.route('/user/<username>')
def raghav(username):
    #do something, get from data base
    
    return username
    
    

@app.route('/sadana')
def sadana():
    return "sadana" #html, JSON, CSV, css 

#Backend - 
