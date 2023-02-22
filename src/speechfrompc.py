import speech_recognition as sr
import serial
import os
from gtts import gTTS

r = sr.Recognizer()
ser = serial.Serial('com6', 57600) // ganti com sesuai port arduino
with sr.Microphone() as source:

def speak(audioString):
    print(audioString)
    tts = gTTS(text=audioString, lang='id')
    tts.save("audio.mp3")
    os.system("mpg321 audio.mp3")

    try:
        while 1:
            
            speak("Hai, katakan apa yang bisa kubantu")
            print('katakan sesuatu !:')
            audio = r.listen(source)
            text = r.recognize_google(audio)
            print("kamu berkata : {}".format(text))
            if (text == "relay on"):
                ser.write(b'1')
            elif (text == "relay off"):
                ser.write(b'2')
            elif (text == "3"):
                ser.write(b'3')

    except:
        print("perintah tidak dikenali")
        speak("maaf, bisakah kamu mengulanginya?")