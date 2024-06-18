import pyautogui
import pyautogui as pg
import time

with open('towrite.txt', 'r') as file:
	data = file.read()

time.sleep(20)
pyautogui.FAILSAFE = False
pg.typewrite(data, 0.20)
