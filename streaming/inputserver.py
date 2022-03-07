from flask import Flask, render_template
from flask_socketio import SocketIO, emit
from evdev import UInput, ecodes
import evdev

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)
socketio.init_app(app, cors_allowed_origins="*")

# can either use ABS_Z ABS_BRAKE
# ecodes for axis
axis = {
    'LeftStickX' : 0,
    'LeftStickY' : 1,
    'RightStickX' : 3,
    'RightStickY' : 4,
    'LeftTrigger' : 2,
    'RightTrigger' : 5
    #'DPadLeft': 16,
    #'DPadRight': 16,
    #'DPadUp': 17,
    #'DPadDown': 17, 
}

# ecodes for button
button = {
    'A': 304,
    'B': 305,
    'X': 307,
    'Y': 308,
    'LB': 310, # R1
    "RB": 311, # R2
    'RT': 312, # right trigger as button - R2
    'LT': 313, # left trigger as button - L2
    'Back': 314,
    'Start': 315
    # 'LS': , # L3
    # 'RS':  # R3
}

#  https://stackoverflow.com/questions/44934309/how-to-access-the-joysticks-of-a-gamepad-using-python-evdev

ui =  UInput() # Maybe specify some more stuff here

S_MAX = 65536

@socketio.event
@socketio.on('axs')
def handle_message(data):
    print('received message: ' + data)
    pair = data.split('|') # pair0 is key pair1 is value
    num = axis[pair[0]]
    ui.write(ecodes.EV_ABS, num, int(float(pair[1])*S_MAX))

@socketio.event
@socketio.on('btn')
def handle_message(data):
    # print('received message: ' + data)
    pair = data.split('|')
    num = button[pair[0]]
    value = 1 if (pair[1] == "true") else 0
    print(value)
    ui.write(ecodes.EV_KEY, num, value)


@socketio.on('connect')
def connected():
    print('Connected')

@socketio.on('disconnect')
def disconnected():
    print('Disconnected')

@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

if __name__ == '__main__':
    socketio.run(app, port=5000,host='0.0.0.0',debug=True)
