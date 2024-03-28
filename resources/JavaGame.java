
package javagame;

import java.util.Scanner;

public class JavaGame {

    public static void main(String[] args) {
        
        String x =Integer.toString((int)(Math.random()*10001));      //Contraseña del terminal
        String Pay = "F";                                            //Easter Egg
        int cont = -1;                                               //Valor de la sala
        int c = 0;                                                   //Número de chapas en el inventario
        int e = 0;                                                   //Experiencia
        int bag =0;                                                  //Valor de la mochila (Llena=0 - Vacía=1)
        int trm = 0;                                                 //Valor del terminal  (Sin tocar=0 - Pirateado=1 - Destruido=3)
        int nc = 0;                                                  //Rango Nuka          (Sí=1 - No=0)
        int nq = 0;                                                  //Rango Quantum       (Sí=1 - No=0)
        int at = 0;                                                  //Rango AtomChild     (Sí=1 - No=0)
        int bb = 0;                                                  //Rango BigBoy        (Sí=1 - No=0)
        int dry =0;                                                  //Valor Sed           (Sí=0 - No=1)
        int ml = 1;                                                  //Multiplicador de expreriencia
        int k = 1;                                                   //Valor terminal      (Game over=4)
        int art= 0;                                                  //Final oculto        (Sí=1 - No=0)
        int v = 0;                                                   //Valor del veneno    (Game over=5)
        int sec = 0;                                                 //Valor del final secreto
        int ext = 1;                                                 //Valor estado        (On=1 - Off=0)
        

//Inicio 

    Scanner teclado=new Scanner (System.in) ;
        
    while (ext==1){  //for (int rep = 1; rep<=10; rep--) { (Método de bucle descartado)
            
    if (v>=1){ v=v+1; e=e-1;
    }      
    if (v==3){
             System.out.println(" ");
             System.out.println("Sientes un ligero hormigueo en los dedos");
             System.out.println(" ");
        }  
    if (v==4){
             System.out.println(" ");
             System.out.println("Te sientes mareado");
             System.out.println(" ");
        }  
    if (v>=5){ cont=1;
             System.out.println(" ");
             System.out.println("El veneno te deja sin fuerzas y te desvaneces");  
             System.out.println("Has perdido");
             System.out.println(" ");
         } 
    if (v==-5){ v=0;
             System.out.println(" ");
             System.out.println("Parece que la radiación de la Nuka Cola Quantum ha contrarrestado el efecto del veneno");
             System.out.println(" ");
         }
            
        if (cont==-1) { cont=-3;
        System.out.println(" ");
        System.out.println("/----------------------------------------------------|"
                       + "\n| Wasteland Tales: La Siniestra Fábrica de Nuka-Cola |"
                       + "\n|----------------------------------------------------/");
        System.out.println(" ");
        System.out.println("Pulsa cualquier tecla para empezar:");
        System.out.println(" ");
        String continuar = teclado.next();
        if (continuar.equals(Pay)) {
        System.out.println(" ");
        System.out.println("You have pay your respects");
          }
         }
        if (cont==-3) { cont=0;
        System.out.println(" ");
        System.out.println("Eres un mensajero del Mojave Express destinado a Yermo Capital");
        System.out.println("Te encuentras fatigado y deshidratado tras tan largo viaje");
        System.out.println("Ante ti yacen los restos de la antigua fábrica de Nuka Cola");
        System.out.println("---------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        System.out.println("1.-Sigues tu camino, parece un lugar peligroso, mejor no correr riesgos"
                + "\n2.-Entras, seguro que dentro hay ingentes cantidades de Nuka Cola"
        +"\n3.-Pateas una lata arrastrada por el viento");
        System.out.println(" ");
         }    
  
//Exterior
            
        if (cont==0) {
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1": cont=1; c=c+250; e=e+1;
            if(v>=1) {
             System.out.println(" ");
             System.out.println("Sigues tu camino hasta La Ciudadela"); 
             System.out.println("El veneno acaba matandote antes de que puedas llegar a algún asentamiento cercano");
             System.out.println("Has perdido");
             }
            if (v==0) {
             System.out.println(" ");
             System.out.println("Sigues tu camino hasta La Ciudadela y completas el encargo");
             System.out.println("Pero acabas muriendo a causa de la deshidratación");
             System.out.println("Has perdido");
             }
             continue;
             
            case "2": cont=2; e=e+2; 
              System.out.println(" ");
              System.out.println("Entras en el edificio");
              System.out.println("Un pequeño foco de luz proviniente de un agujero en la pared ilumina la oscura habitación");
              System.out.println("Huele a humedad y a cerrado, no ha pasado nadie por aquí en mucho tiempo");
              continue;
              
            case "3":  
            if (v==0) { e=e-1; v=v+1; cont=-3;
              System.out.println(" ");
              System.out.println("Dentro de la lata hay un mutascorpius venenoso que te pica en la pierna");
              System.out.println("El veneno de estos insectos es de acción rápida, debo encontrar algo que neutralice el veneno");
            }
            else {
              System.out.println(" ");
              System.out.println("Hacerlo una vez ya fue estúpido, si volviese a patear la lata en que me convertiría...");  
             }
              continue;
              
            case "1Art3misa1":cont=9; e=e+999; c=c+9999; art=1;
             System.out.println(" ");
             System.out.println("Definitivamente no deberías estar viendo esto");
              continue;
         }
        }

//Sala A

    if (cont==2) {
        if (sec==-2){
        System.out.println("En la sala de la izquierda es donde reposaba el mutante");  
         }
        else {
        System.out.println("Se escuchan unos quejidos sospechosos en la sala que se encuentra a tu izquierda");
         }
        System.out.println("De la sala que tienes enfrente vienen unos ruidos ensordecedores de maquinaria");
        System.out.println("Y por último el pasillo que tienes a tu derecha parece levemente iluminado por una luz azul celeste");
        System.out.println("---------------------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        if (sec==-2){
        System.out.println("1.-Vuelves a la cafetería");
         }
        else {
        System.out.println("1.-Puede que alguien esté herido y necesite ayuda, y también desvalido es una buena oportunidad para hacer botín");
         }
        System.out.println("2.-¡Máquinas monstruo a mi!"
                +"\n3.-Sientes como ese brillo azul te empieza a atraer poco a poco"+"\n4.-Mejor será que me vaya, soy alergico al polvo...");
        System.out.println(" ");
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1": cont=4; 
            if (sec>=1){ sec=sec+1;
             }
            if (sec==4){ sec=0;
             }
            System.out.println(" ");
            System.out.println("Pese a que tu intuicón te dice que no, acabas entrando a la sala de la izquierda");
            System.out.println("Es la cafetería de la fábrica");
            System.out.println("Recostado en una de las paredes se deja ver un bulto");
            continue;
            
            case "2": cont=5; 
            if (sec==3) { sec=-1;
             }
            if (sec==2) { sec=0;
             }
            if (sec==1) { sec=0;
             }
            if (sec==-2) { cont=7;
            System.out.println(" ");
            System.out.println("¡El necrofago se está enfrentando a dos señores mañosos!");
            System.out.println("El duo de robots estan ganando terreno a la desdichada bestia, sería una pena que alguien interviniese...");
             }
            else {
            System.out.println(" ");
            System.out.println("Entras a una sala enorme llena de chatarra en la que se encuentra una máquina monstruosa");
            System.out.println("La gigantesca mole de hierro es la embotelladora de Nuka Cola");
            System.out.println("Hace mucho ruido pero no parece hacer nada");
             }
            continue;
            
            case "3": cont=6; 
            if (sec>=1) { sec=0;
             }
            System.out.println(" ");
            System.out.println("Sigues el destello del pasillo como aturdido,al igual que las tochomoscas a los generadores eléctricos RobCo ");
            continue;
            
            case "4": cont=1; v=0;
            if (sec==-2){ cont=9; bb=1; e=(e+10)*ml; c=c+5000;
            System.out.println(" ");
            System.out.println("Te das cuenta que no ha sido buena idea entrar y decides salir por donde has venido");
            System.out.println("La puerta está atascada, tiras del pomo como si un yaoguai te estuviese intentando robar el almuerzo");
            System.out.println("La fuerza bruta nunca es la solución, así que decides volar la puerta en pedazos con tu reciente adquisición");
            System.out.println("Cargas cuidadosamente el proyectil en el fat-man");
            System.out.println("Un silbido agudo suena indicandote que esta listo para disparar");
            System.out.println("Te colocas a una distancia segura y accionas el gatillo");
            System.out.println("La granada impacta en la puerta a una velocidad vertiginosa");
            System.out.println("Pero esta en vez de estallar abre un boquete en la podrida madera dejando escapar al artefacto y provocando que el techo aledaño a la puerta se venga abajo");
            System.out.println("Escuchas una explosión seguida de gritos, parece que al viejo proyectil no le bastaba con un simple pedazo de madera");
            System.out.println("Trepas por los escombros de la entrada para contemplar a las víctimas de la granada insurrecta");
            System.out.println("¡El explosivo ha impactado de lleno en una patrulla del Enclave!");
            System.out.println("Registras los restos del 'accidente' y encuentras un jugoso botín: 5000 chapas y un rifle de plasma nuevecito con su correspondiente munición");
            System.out.println("¡Resulta que una de las servoarmaduras sigue siendo funcional!¡Y el soldado que la portaba tiene encima un 'six pack' de Nuka Cola Quantum!");
            System.out.println("Y así, pertrechado con las mejores armas que la cienda puede proporcionar y con la certeza de que no vas a pasar sed durante una temporada");
            System.out.println("Partes hacia La Ciudadela cual caballero de antaño con tu armadura resplandeciendo al sol");
             }
            else {
            System.out.println(" ");
            System.out.println("Te das cuenta que no ha sido buena idea entrar y decides salir por donde has venido");
            System.out.println("La puerta está atascada, tiras del pomo como si un yaoguai te estuviese intentando robar el almuerzo");
            System.out.println("La puerta se abre, pero el techo vence, dejando caer escombros y un señor mañoso estropeado que acaban por aplastarte");
            System.out.println("Has perdido");
             }
            continue;
     }
    }
    
    //Sala B
    
    if (cont==4) {
        if (sec==-2) {
        System.out.println("El necrófago ya no se encuentra en la sala");
        System.out.println("Pero la bolsa sigue en su sitio");
        System.out.println("-------------------------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        System.out.println("1.-Ya tengo todo lo que necesito, mejor me doy la vuelta"
                + "\n2.-¿Qué habrá en la mochila?"
                +"\n3.-Voy a volver a revisar el agujero de la pared");
        System.out.println(" ");
         }
        else {
        System.out.println("Te acercas muy lentamente al cuerpo");
        System.out.println("La luz no te deja distinguir muy bien los detalles pero a simple vista parece una persona enferma");
        System.out.println("Viste con harapos y tiene una complexion excesivamente delgada. A su lado se puede distinguir una bolsa");
        System.out.println("Tras pensar detenidamente te decides a actuar");
        System.out.println("-------------------------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        System.out.println("1.-Es probable que sea un necrofago y la mordedura del último hizo que el brazo me brillase en la oscuridad, doy la vuelta"
                + "\n2.-Mi Pip-Boy dice que tengo el rango de sigilo alto, me voy a arriegar a quitarle la mochila"
                +"\n3.-Los necrófagos son aberraciones, lo voy a patear");
        System.out.println(" ");
         }
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1": cont=2; 
                System.out.println(" ");
                System.out.println("Vuelves a la sala principal");
            continue;
            
            case "2": 
            if(bag==0) {  e=e+2; bag=1; c=c+500;
                System.out.println(" ");
                System.out.println("Consigues robar exitosamente la mochila y dentro te encuentras 500 chapas y una nota amarillenta");
            if (sec==-2) { cont=4;
                System.out.println("Vuelves a la entrada de la habitación");
             }
            else { cont=2;
                System.out.println("En la nota aparecen los siguientes números " +x);
                System.out.println("Sales rápidamente antes de que el necrófago se de cuenta");
             }
            }
            else { cont=2;
                System.out.println(" ");
                if (sec==-2) { cont=4;
                System.out.println("La mochila no tiene nada de valor");
                 }
                else {
                System.out.println("La mochila no tiene nada de valor, solo la nota con los números");
                System.out.println(" ");
                System.out.println( x );
                System.out.println(" ");
                System.out.println("Sales rápidamente de la cafetería antes de que el necrófago se de cuenta");
                 }
                System.out.println("Vuelves a la sala principal");
                
            }
            continue;
            
            case "3": e=e+1;
            if (v==4){ v=0;
                }
            if (sec==-2){ cont=4;
            System.out.println(" ");
            System.out.println("No hay nada, solo escombros");  
             }
            else {
            System.out.println(" ");
            System.out.println("Pateas al monstuo");
            System.out.println("Pese a ser un alfeñique y estar en descomposición tiene mucha fuerza y agilidad");
            System.out.println("¡Es una necrófago segador!");
            if (sec==-1) { cont=4; sec=-2; e=e+3;
            System.out.println("El zombie se levanta rápidamente");
            System.out.println("Pero por alguna razón pasa de largo y no te ataca");
            System.out.println("Te sobresaltas al ver tu reflejo en lo que queda de un espejo colgado en la pared");
            System.out.println("¡Pareces un necrófago resplandeciente! El veneno ha debido reaccionar con la Nuka Cola");
            System.out.println("En la pared donde estaba recostado el necrófago encuentras un lanzagranadas fat-man con una cabeza nuclear");
            System.out.println("Esto se va poner interesante");
             }
            else { cont=1;
            System.out.println("No te da tiempo a desenfundar el arma antes de que la abominación te salte al cuello");
            System.out.println("Has perdido");
             }
            }
            continue;
     }
    }
    
    //Sala C
    
    if (cont==5) {
        
        if (trm==0) {
            System.out.println("Parece que la máquina se puede apagar, hay un terminal en una de las columnas de la sala");
            
         }
        if (trm==1) {
            System.out.println("No hay energía, pero el terminal sigue encendido");
         }
        if (trm==3) {
            System.out.println("El terminal es chatarra");
         }
        System.out.println("Cerca de la puerta hay unas escaleras que llevan al piso superior, parece una oficina");
        System.out.println("-------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        System.out.println("1.-Pirateo el terminal, mi padre me enseño a trabajar con lenguaje de programación RCO"
                + "\n2.-Subo al piso superior" +"\n3.-Machaco el terminal, la programación es para empollones" +"\n4.-Mejor regreso a la puerta de la entrada");
        System.out.println(" ");
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1":
            if (trm==1) {
                cont=5;
                System.out.println(" ");
                System.out.println("El terminal está bloqueado");
             }
            if (trm==3) {
                cont=5;
                System.out.println(" ");
                System.out.println("Dificilmente...");
                
             }
            if (trm==0) { cont=5; 
            System.out.println(" ");
            System.out.println("La embotelladora no se puede apagar desdel terminal, pero puedes desviar la corriente que alimenta la sala");
            System.out.println("¡Maldición! El terminal requiere contraseña numérica");
            System.out.println(" ");
            System.out.println("Introduce la contraseña");
            System.out.println(" ");
            String x1 = teclado.next();
            if (x.equals(x1)) { trm=1; e=e+2; c=c+1000;
            System.out.println(" ");
            System.out.println("Contraseña aceptada");
            System.out.println(" ");
            System.out.println("El ruido cesa y vuelves a la entrada de la habitación, de vuelta te encuentras una caja mohosa llena de brillantes "
                    +"chapas nuevecitas");
             }
            else { k=k+1;
               
            if (k==4) { cont=1;
                System.out.println(" ");
                System.out.println("El terminal se bloquea y saltan las alarmas");
                System.out.println("La computadora se empieza a calentar");
                System.out.println("Desprende un brillo rojo de aspecto peligroso");
                System.out.println("Tus reflejos de ratatopo de escayola se quedan cortos y el terminal te explota en las narices");
                System.out.println("Has perdido");
                
                    }
            if (k!=4) {
                System.out.println(" ");
                System.out.println("Contraseña incorrecta");
                System.out.println(" ");
                System.out.println("Abandonas el terminal y vuelves a la entrada");
              }
             }
            }
            
            continue;
            
            case "2":
            if (v==4){ v=0;
                }
            if (trm==0){ cont=1;
            System.out.println(" ");
            System.out.println("Subes a la oficina por unas escaleras metálicas jerrumbrosas");
            System.out.println("¡Maldición! hay una torreta de seguridad y al detectarme se activan las alarmas");
            System.out.println("La alarma atrae a dos señores mañosos que operan en la fábrica");
            System.out.println("Entre la torreta y los robots te hacen picadillo(literalmente)");
            System.out.println("Has perdido");
             }
            if (trm==1) { cont=9; c=c+2000; c=c-55; e=e*ml+5; nq=1;
                System.out.println(" ");
                System.out.println("Subes a la oficina por unas escaleras metálicas jerrumbrosas, que parecen retorcerse a cada paso haciendo más ruido que la propia máquina");
                System.out.println("Es un despacho muy bien equipado y bastante lujoso");
                System.out.println("Encuentras un rifle laser de triple haz ¡Cómo los que llevan los caciques super mutantes! y un saco con 2000 chapas");
                System.out.println("El ruido de los escalones ha atraido a unos robots operarios del edificio");
                System.out.println("Con tu nueva arma no te suponen un problema");
                System.out.println("Sales del edificio en el momento que pasa una caravana de suministros");
                System.out.println("Cambias cincuenta y cinco chapas por una Nuka Cola Quantum y habiendo repuesto fuerzas y con una nueva historia que contar prosigues tu camino a la ciudadela");
             }
            if (trm==3) { cont=9; c=c+1000; e=e*ml+2; nc=1;
                System.out.println(" ");
                System.out.println("Subes a la oficina por unas escaleras metálicas jerrumbrosas");
                System.out.println("Es un despacho muy bien equipado, encima de la mesa hay una bolsa con chapas");
                System.out.println("Mientras las cuentas te ataca un operario robot que ha subido sigilosamente por las escaleras");
                System.out.println("El botin se desperdiga por todo el despacho");
                System.out.println("Recoges las pocas chapas que puedes, sales por una ventana y bajas por la escalera de incendios exterior");
                System.out.println("El señor mañoso se escacharra golpeandose contra el suelo al vencer las escaleras, dejando caer una botella de Nuka Cola");
                System.out.println("Y así con una historia nueva y la sed calmada continuas tu viaje a la ciudadela");
            
            
             }
            continue;
            
            case "3":
            if (trm==3){
                System.out.println(" ");
                System.out.println("¡Unga unga!");
             }
            
            if (trm==0) {trm=3; cont=5; e=e+1; 
                System.out.println(" ");
                System.out.println("Alardeando de toda tu fuerza primitiva plastas el teminal con un pedazo de escombro que encuentras en el suelo");
                System.out.println("Mil chispas revolotean por los alrededores");
                System.out.println("Una alarma estridente suena por unos pocos segundos para quedarse todo en silencio");
                System.out.println("No hay electricidad");
                System.out.println("Un señor mañoso aparece en escena destrozando todo a su paso");
                System.out.println("Lo derrotas a duras penas con los restos del terminal que ha pasado a mejor vida");
             }
            if (trm==1){
                System.out.println(" ");
                System.out.println("No parece necesario, mejor ahorrar fuerzas");
             }
            continue;
            
            case "4": cont=2;
                 System.out.println(" ");
                 System.out.println("Regresas a la entrada");
            
            continue;
            
        }
    }
    
//Sala C Final alterno

   if (cont==7) {
        System.out.println("-------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        System.out.println("1.-Intervenir, por supuesto; esos tres van a sentir en sus carnes el poder del átomo"
               + "\n2.-No me gustan los lios, mejor les dejo tranquilos...");
        System.out.println(" ");
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1": cont=9; c=c+3500; e=(e+5)*ml; at=1;
            System.out.println(" ");
            System.out.println("Cargas cuidadosamente el proyectil en el fat-man");
            System.out.println("Un silbido agudo suena indicandote que esta listo para disparar");
            System.out.println("Te colocas a una distancia segura y accionas el gatillo");
            System.out.println("Al impactar el proyectil se produce una explosión monumental que anula todos tus sentidos");
            System.out.println("Cuando despiertas te das cuenta de que la explosión te ha sacado del edificio... Bueno, lo que queda de él");
            System.out.println("De pie, a tu lado se encuentran unos comerciantes de caravanas"
                    + "\nObservando como el humo que sale del crater donde antes estaba la fábrica se eleva hipnóticamente");
            System.out.println("El lanzagranadas de poco te vale sin munición, así que se lo cambias a los comerciantes por tres una Nuka Cola y Dos Nuka cola Quantum");
            System.out.println("Y así, magullado pero exitoso prosigues tu camino a La Ciudadela, brillante como una Nuka Cola Quartz y con el gaznate refrescado, Esperemos que allí tengan gran cantidad rad-away");
            continue;
            
            case "2": cont=2;
            System.out.println(" ");
            System.out.println("Regresas a la entrada");
            continue;
    }
   }
    
//Sala D

    if (cont==6) {
        
        System.out.println("Según avanzas por el cavernoso corredor la luz se torna más intensa");
        System.out.println("El pasillo desemboca en una sala enorme y luminosa inundada en su gran mayoría por un líquido azul");
        System.out.println("¡El liquido azul es Nuka Cola Quantum! La joya de la corona de John C.Bradberton");
        System.out.println("El preciado trago esta custodiado por unos repugnantes hombres pinza resplandecientes");
        System.out.println("--------------------------------------------------------------------------------------------------");
        System.out.println(" ");
        System.out.println("¿Qué haces?");
        if (sec==-2) {
        System.out.println("1.-Con lo volatil que es la Quantum sería una locura usar aquí el fat-man... ¿No?");    
         }
        else {
        System.out.println("1.-Arriesgarme a darle un trago");
         }
        System.out.println("2.-Correr como alma que lleva al diablo, esos bichos son mortíferos");
        System.out.println(" ");
        
        String nxt = teclado.next();
        
        switch (nxt) {
            
            case "1":
            if (dry==0) { cont=2; e=e+3; dry=1; ml=2;
            if (v==4){v=-5; sec=1;
             }
            System.out.println(" ");
            System.out.println("Con las manos formas un cuenco y le das un gran sorbo a la Nuka Cola");
            System.out.println("Los hombres pinza te han visto, y te ves obligado a huir");
            System.out.println("Vuelves a la sala principal");
             }
            else  { cont=1;  e=e-2;
            if (sec==-2) { cont=1; e=e+23;
            System.out.println(" ");
            System.out.println("Decides hacer pastel de cangrejo a la Nuka Cola volando por los aires a los acuáticos inquilinos de la fábrica");
            System.out.println("Nada más impactar la granada contra los hombres pinza la Nuka Cola Quantum reacciona a la radiación"); 
            System.out.println("De una manera tan violenta que la explosión puede sentirse en el Jefferson Memorial");
            System.out.println("Jamás se volvió a saber del mensajero tras el desastre apodado como 'Segundo Megatón'");
            System.out.println("Has perdido");
             }
            else {
            if (v==4){ v=0;
                }
            System.out.println(" ");
            System.out.println("Los hombres pinza no perdonan y tus restos acaban formando parte de sus nidos");
            System.out.println("Has perdido");
              }
             }
            continue;
            
            case "2": cont=2;
            System.out.println(" ");
            System.out.println("Caminas sobre tus pasos");
            System.out.println("Vuelves a la sala principal");
            
            continue;
            
        }
    }
     
//Finales

        if (cont==1){ cont=-2;
            System.out.println(" ");
            System.out.println("Chapas en posesión: " +c);
            System.out.println("Nivel conseguido: " +e);
                    }

        if (cont==9)   { cont=-2;
            
            System.out.println(" ");
            System.out.println("Chapas en posesión: " +c);
            System.out.println("Nivel conseguido: " +e);
            if (nc==1) {
            System.out.println("Rango: Nuka");
             }
            if (nq==1) {
            System.out.println("Rango: Quantum");
             }
            if (art==1){
            System.out.println("Rango: ArrowInTheKnee!");
             }
            if (bb==1){
            System.out.println("Rango: BigBoy");
             }
            if (at==1){
            System.out.println("Rango: AtomChild");
             }
            System.out.println(" ");
            System.out.println("/-----------------------------------------------------------------------------------------------|"
                    +        "\n|                                                                                               |"
                    +        "\n|  !Felicidades! has completado el capítulo Wasteland Tales: La Siniestra Fábrica de Nuka-Cola  |"
                    +        "\n|                                                                                               |"
                    +        "\n|                                      Producido por ELB24                                      |"
                    +        "\n|                                                                                               |"
                    +        "\n|-----------------------------------------------------------------------------------------------/");
                       }     
        if (cont==-2) {
            
            System.out.println(" ");
            System.out.println("¿Volver a jugar?(Y/N)");
            System.out.println(" ");
            
            String nxt = teclado.next();
            
            switch (nxt) {
            
            case "Y":
            case "y":cont=-1; e=0; c=0; ml=0; v=0; dry=0; sec=0; trm=0; bag=0; nc=0; nq=0; at=0; bb=0; k=1;
            System.out.println(" " + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n");
            break;
            
            case "N":
            case "n": ext=0;
            System.out.println(" ");
            break;
            }
         }
      }  
   }
}