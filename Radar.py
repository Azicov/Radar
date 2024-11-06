import pygame
import serial
import csv
import time
import math
"""test"""
ser = serial.Serial('COM9', 115200, timeout=1)

clock = pygame.time.Clock()

pygame.init()

screen = pygame.display.set_mode((800,400))

surface =pygame.Surface((800,400),pygame.SRCALPHA)

fi = math.pi
gama = 0
lamaie = math.pi/180
latime_linie = 5

run = True
screen.fill((255,255,255))
#de aici incepem loop-ul
while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    #time.sleep(0.001)

    try:
        x=ser.readline()
        gama = int(x.decode("utf-8"))
    except ValueError:
        print()
#pentru transformare in intervalul 0,400
    if gama > 20:
        gama = 400
    else :
        gama = gama*20

    if fi>=math.pi-0.01 and fi<=2*math.pi:
        fi+=lamaie
        pygame.draw.line(screen,'red',(400,400),(400+400*math.cos(fi),400+400*math.sin(fi)),latime_linie)
        pygame.draw.line(screen,'blue',(400,400),(400+gama*math.cos(fi),400+gama*math.sin(fi)),latime_linie+2)
    elif fi>=2*math.pi and fi<3*math.pi-0.02:
        fi+=2*math.pi
    elif fi>3*math.pi+0.01 and fi<=4*math.pi+1 :#aici am pus +1 deoarece aparea o problema la pi*4 el fiid un pic inmultit gresit
        fi-=lamaie
        pygame.draw.line(screen,'red',(400,400),(400+400*math.cos(fi),400+400*math.sin(fi)),latime_linie)
        pygame.draw.line(screen,'blue',(400,400),(400+gama*math.cos(fi),400+gama*math.sin(fi)),latime_linie+2)
    elif fi<=3*math.pi and fi>= math.pi:
        fi-=2*math.pi
    print(fi,gama)

    screen.blit(surface,(0,0))
    pygame.draw.rect(surface,(255,255,255,2),[0,0,800,800])

    pygame.display.update()
    
    clock.tick(60)
#final loop
pygame.quit()