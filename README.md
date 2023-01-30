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

Nous utilisons 


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
Nous avons également défini les temps morts des PWM à l'aide de cette vidéo : https://www.youtube.com/watch?v=rDaC2N-33Oo
	
Cela nous permet de trouver dead_time=202.

Voici la fonction permettant de lancer les deux PWM et leur complémentaire à la valeur définie dnas l'ioc 

<figure> <br/>
	<figure>
    <img src="https://user-images.githubusercontent.com/93315587/213122016-3d2dcf36-c4f7-4379-8a16-3c0b67d3152d.png"
         alt="figure 3">
    <figcaption>Figure 3 : Géneration des PWM </figcaption>
<figure> <br/>


<figure> <br/>
	<figure>
    <img src="https://user-images.githubusercontent.com/93315587/213146788-e96c984f-db73-437f-b63e-f9d675710a13.png"
         alt="figure 4">
    <figcaption>Figure 4 : Illustration sur l'IOC </figcaption>
<figure> <br/>

# Alimentation directe du hacheur 

Une fois que nous avons créé nos PWM, nous allons les envoyer dans notre hacheur afin de savoir si ces PWM font bien fonctionner notre hacheur, pour ce faire nous allons regarder sur la documentation les branchement du hacheur et de la Nucleo. 


![pinhacheur](https://user-images.githubusercontent.com/93315587/214108723-0c3bd23e-149c-403d-8b05-f0aa457ece50.png)

Une fois que l'on arrive à piloter le moteur en envoyant les PWM nous allons créer une liaison UART afin de modifier la commande des PWM et ainsi faire varier la vitesse du moteur. Pour ce faire nous crééons une variable qui agit sur les deux PWM afin de faire tourner le moteur dans un sens ou dans l'autre selon la valeur entrée. Cependant, l'appel de courant ne doit pas être trop important et par conséquent on est obligé de commencer à une valeur très proche d'une vitesse de rotation nulle (ici 512)

Nous créeons donc une shell dans laquelle nous allons effectuer des fonctions 
<figure> <br/>
	<figure>
    <img src="https://user-images.githubusercontent.com/93315587/215481896-b71b586e-c9b9-4642-90ea-fcbbc688a896.png"
         alt="figure 5">
    <figcaption>Figure 5 : Lancement de la shell </figcaption>
<figure> <br/>

Nous lançons ensuite la fonction motorSetSpeed dans la shell, cette fonction fait varier les PWM 

![speed](https://user-images.githubusercontent.com/93315587/215481374-fb1801a0-1685-40ce-ba2d-0fcd07a1e66f.png)
