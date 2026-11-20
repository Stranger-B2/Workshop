# 🐣 S1 | # Rapport de Workshop


Template de projet pour le workshop de prog des Imac1. Vous trouverez le sujet ici: https://dsmte.github.io/Learn--cpp_programming/Workshop

**image de départ**

![green picture](images/caniche.jpg)

## ⭐ Ne garder que le vert

![green picture](output/final/star%201/green.png)

## ⭐ Échanger les canaux

**échange le rouge et le rouge, puis le vert et le rouge, puis bleu vert et enfin rouge bleu**

![redred picture](output/final/star%201/switchrr.png)
![greenred picture](output/final/star%201/switchgr.png)
![bluegreen picture](output/final/star%201/switchbg.png)
![redblue picture](output/final/star%201/switchrb.png)

**Cette fonction m'a donné un peu de fil à retordre car j'ai du utilisé plusieurs fonction qui modifier des pixel mais avait oublié que les images était des copies et non des références**

## ⭐ Noir & Blanc

![black&white picture](output/final/star%201/black&white.png)

## ⭐ Négatif

![negatif picture](output/final/star%201/negatif.png)

## ⭐ Dégradé

![dégradé picture](output/final/star%201/degrad.png)

## Degrad d'image

**prend une image et fait un fondu blanc vert la droite**

![dégradé picture](output/final/star%201/test.png)

## ⭐⭐ Miroir

![miroir picture](output/final/star%202/miroir.png)

## ⭐⭐ Image bruitée

![sound picture](output/final/star%202/sound.png)

## ⭐⭐ Rotation de 90°

![right picture](output/final/star%202/rotationRight.png)
![left picture](output/final/star%202/rotationLeft.png)

## ⭐⭐ RGB split

![rgb picture](output/final/star%202/dephasage.png)

## ⭐⭐ Luminosité

![dark picture](output/final/star%202/luminoDark.png)
![regular picture](images/caniche.jpg)
![light picture](output/final/star%202/luminoLight.png)

## ⭐⭐(⭐) Disque

![disque picture](output/final/star%203p/disque.png)
![disque left picture](output/final/star%203p/disqueLeft.png)
![disque out of range picture](output/final/star%203p/disqueOutofRange.png)

## ⭐⭐ Cercle

![disque picture](output/final/star%203p/cercle.png)
![disque picture](output/final/star%203p/cerclefin.png)
![disque left picture](output/final/star%203p/cercleEpaisseurMAx.png)
![disque out of range picture](output/final/star%203p/cercleEppaisseurNegative.png)

## ⭐⭐ Animation

![circle animation](output/final/animation.gif)

## ⭐⭐⭐ Rosace

![rosace picture](output/final/star%203p/rosace.png)
![rosace picture](output/final/star%203p/rosaceSmall.png)

## rosace Croissant
![rosace picture](output/final/star%203p/rosaceCroissant.png)

## ⭐⭐ Mosaïque

![mosaique picture](output/final/star%203p/mosaique.png)
![big mosaique picture](output/final/star%203p/mosaique50.png)

## ⭐⭐⭐⭐ Mosaïque miroir

![mosaique mirror picture](output/final/star%203p/mosaiqueMirror.png)

## mosaique mixed

**lors de la création de mosaique mirroir, par erreur au lieu de faire mirroir à chaque itération de l'image, je l'avais fait sur chaque pixel, obtenant ansi ce résultat**

![mosaique mixed picture](output/final/star%203p/mosaiqueMirrorBug.png)
![mosaique mixed big picture](output/final/star%203p/mirrorbug5.png)

## ⭐⭐⭐(⭐) Fractale de Mandelbrot

**après avoir réussit à obtenir une fractale réussit j'ai décidé d'essayer d'augmenter la puisance de la formule z = z x z + c en z = z x z x z +x, voici le résultat de la puissance 0 à la puissance 19**

<img src="output/final/fractalPuissance/puissance0,0/0.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/1.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/2.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/3.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/4.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/5.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/6.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/7.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/8.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/9.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/10.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/11.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/12.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/13.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/14.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/15.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/16.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/17.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/18.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,0/19.000000.png" width="200">

**en modifiant de sorte à ne pas commencé par z = 0 +0i mais par 1+ 0i, ensuite 0+ i et finalement 1+i on obtient ces résultat là, on remarque qu'un coté de la fractale augmente trop vite éxplicant l'absence de pointes dans les images suivantes**

<img src="output/final/fractalPuissance/puissance0,1/0.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/1.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/2.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/3.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/4.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/5.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/6.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/7.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/8.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/9.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/10.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/11.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/12.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/13.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/14.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/15.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/16.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/17.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/18.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance0,1/19.000000.png" width="200">

<img src="output/final/fractalPuissance/puissance1,0/puissance0.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance1.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance2.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance3.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance4.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance5.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance6.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance7.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance8.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance9.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance10.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance11.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance12.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance13.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance14.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance15.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance16.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance17.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance18.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,0/puissance19.000000.png" width="200">


<img src="output/final/fractalPuissance/puissance1,1/0.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,1/1.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,1/2.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,1/3.000000.png" width="200">
<img src="output/final/fractalPuissance/puissance1,1/4.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/5.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/6.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/7.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/8.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/9.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/10.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/11.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/12.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/13.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/14.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/15.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/16.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/17.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/18.000000.png" width="20">
<img src="output/final/fractalPuissance/puissance1,1/19.000000.png" width="20">

## ⭐⭐⭐(⭐) Dégradés dans l'espace de couleur Lab

![green picture](output/final/star%203p/DegradColor.png)
![green picture](output/final/star%203p/DegradColor2.png)

## ⭐⭐⭐(⭐) Tramage
**le tramge m'a donné bcp de fil à retordre, devoir lire 2 document certes intéressant mais pas forcémeent claire m'a pris pas mal de temps. De plus std::pow semble marcher à première vue, mais ne gère pas les nombres négatif, cette exercice fut tout de même très satisfaisant à accomplir**

**Noir et blanc**

<img src="output/final/tramage/tramagePart1.png" width="200">

**Noir et blanc avec aléatoire plus ou moins fort**

<img src="output/final/tramage/tramagePart2alea1.png" width="200">
<img src="output/final/tramage/tramagePart2alea10.png" width="200">
<img src="output/final/tramage/tramagePart2alea2.png" width="200">
<img src="output/final/tramage/tramagePart2alea3.png" width="200">
<img src="output/final/tramage/tramagePart2alea4.png" width="200">
<img src="output/final/tramage/tramagePart2alea5.png" width="200">
<img src="output/final/tramage/tramagePart2alea6.png" width="200">
<img src="output/final/tramage/tramagePart2alea7.png" width="200">
<img src="output/final/tramage/tramagePart2alea8.png" width="200">
<img src="output/final/tramage/tramagePart2alea9.png" width="200">

**Noir et blanc avec matrice 2*2*

<img src="output/final/tramage/tramagePart3puiss1.png" width="200">
<img src="output/final/tramage/tramagePart3puiss1_5.png" width="200">
<img src="output/final/tramage/tramagePart3puiss2.png" width="200">
<img src="output/final/tramage/tramagePart3puiss2_5.png" width="200">
<img src="output/final/tramage/tramagePart3puiss3.png" width="200">
<img src="output/final/tramage/tramagePart3puiss4.png" width="200">

**Noir et blanc avec matrice 4*4*

<img src="output/final/tramage/tramagePart4_1.png" width="200">
<img src="output/final/tramage/tramagePart4_2.png" width="200">
<img src="output/final/tramage/tramagePart4_3.png" width="200">
<img src="output/final/tramage/tramagePart4_4.png" width="200">
<img src="output/final/tramage/tramagePart4_5.png" width="200">

## ⭐⭐⭐(⭐) Normalisation de l'histogramme
**la nomalisation semble fonctionner mais je pense qu'il y a un problème avec les images monochrome, ou les courtes fréquences de couleurs**

![normal picture](output/final/star%204p/normal.png)

## ⭐⭐⭐⭐ Vortex
**j'ai eu pas mal de difficulté a comprendre comment avoir un vortex sans trou, cependant ça m'a permit d'obtenir ces résultats hypnotiques fort sympatique**

![normal picture](output/final/star%204p/vortex.png)
![normal picture](output/final/star%204p/circles.png)
![normal picture](output/final/star%204p/drug.png)
![normal picture](output/final/star%204p/hypppno.png)
![normal picture](output/final/star%204p/vortex360.png)

## ⭐⭐⭐⭐⭐⭐ Diamond Square
**j'ai adoré cette exercice, un algo fascinant qui permet d'obtenir des résultats utiles, j'ai donc fait plusieurs version dont certaine très aléatoire comme la dernière ci-dessous**

<img src="output/final/diamond%20Square/gazRandom.png" width="200">
<img src="output/final/diamond%20Square/diamond.png" width="200">
<img src="output/final/diamond%20Square/gaz2.png" width="200">
<img src="output/final/diamond%20Square/gazclean.png" width="200">
<img src="output/final/diamond%20Square/randomMax.png" width="200">

## ⭐⭐ Colorer la height map

<img src="output/final/diamond%20Square/map2.png" width="200">
<img src="output/final/diamond%20Square/land.png" width="200">
<img src="output/final/diamond%20Square/landes%20of%20fire.png" width="200">
<img src="output/final/diamond%20Square/pitoresque.png" width="200">
<img src="output/final/diamond%20Square/rift.png" width="200">
<img src="output/final/diamond%20Square/rives.png" width="200">
<img src="output/final/diamond%20Square/corridor.png" width="200">
<img src="output/final/diamond%20Square/map.png" width="200">
<img src="output/final/diamond%20Square/water.png" width="200">

** j'espère que ce rapport vous a plu, les fonctions sont toutes mises en commentaires si vous avez un doute sur leur fonctionnement **


<img src="output/final/DegradAsh.png" width="1000">