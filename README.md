CLEMENT Pierre
HANNANI Hamza

## TP Commande Numérique directe de dispositifs : commande d’une MCC par le biais d’un hacheur

## SOMMAIRE

1. Introduction <br/>
2. Creation des PWM <br/>
3. Alimentation directe du hacheur <br/>
4. Console UART <br/>
5. Commande du moteur finale <br/>
6. Courants et ADC

# Introduction

Dans le cadre de ces séances de travaux pratiques, nous allons étudier la commande d'un moteur faite de façon numérique avec une carte NUCLEO qui commande notre hacheur afin de commander le moteur. Pour ce faire, nous allons envoyer des PWM en commande décalée au hacheur afin que celui-ci alimente notre moteur correctement. Nous allons commander l'amplitude des PWM et donc la vitesse du moteur par le biais d'une console UART  
