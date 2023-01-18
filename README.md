CLEMENT Pierre
HANNANI Hamza

### TP Commande Numérique directe de dispositifs : commande d’une MCC par le biais d’un hacheur

## SOMMAIRE

1. Introduction <br/>
2. Creation des PWM <br/>
3. Alimentation directe du hacheur <br/>
4. Console UART <br/>
5. Commande du moteur finale <br/>
6. Courants et ADC

# Introduction

Dans le cadre de ces séances de travaux pratiques, nous allons étudier la commande d'un moteur faite de façon numérique avec une carte NUCLEO qui commande notre hacheur afin de commander le moteur. Pour ce faire, nous allons envoyer des PWM en commande décalée au hacheur afin que celui-ci alimente notre moteur correctement. Nous allons commander l'amplitude des PWM et donc la vitesse du moteur par le biais d'une console UART. Ensuite, une fois que notre moteur sera piloté par le biais de la console UART, nous allons envoyer des consignes de vitesse, cette consigne est ensuite traduite en PWM pour le moteur. Le moteur piloté via la console UART, on va ensuite récupérer ses valeurs de courant afin de pouvoir asservir notre moteur par la biais de la boucle de courant.

# Génération des PWM 

Nous décidons de génerer 2 PWM et leur complémentaire (afin de piloter le moteur en commande complémentaire). Ces deux PWM sont génerées sur le même timer, TIMER1. Cependant, nous devons nous assurer de bien avoir une horloge à 16kHZ. Pour ce faire, nous devons réduire la fréquence d'horloge globale grâce aux valeurs du prescaler (PSC) et de l'auto reload register (ARR). L'horloge du timer étant de 170Mhz, on peut par exemple utiliser PSC=11-1=10 et ARR=1024-1=1023. Ces valeurs nous permettent de générer des PWM avec une demi période de 16kHz comme esperé après vérification à l'oscilloscope.

<figure>
    <img src="https://user-images.githubusercontent.com/93315587/213118470-af036310-80aa-4fb5-99fc-738890ca2e1e.jpg"
         alt="figure 1"
	 height="300" 
	 width="300">
    <figcaption>Figure 1 : Capture d'une PWM à 16kHz avec un rapport cyclique de 50% </figcaption>
	
<figure> <br/>
	<figure>
    <img src="https://user-images.githubusercontent.com/93315587/213119450-306a818c-ba9a-4046-84dd-4368ec467a55.jpg"
         alt="figure 2"
	 height="300" 
	 width="300">
    <figcaption>Figure 2 : Capture d'une PWM à 16kHz avec un rapport cyclique de 75% </figcaption>
<figure> <br/>

	
	
