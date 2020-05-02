## GermainLib

 **GermainLib** est une librairie développée en C couvrant plusieurs aspects du C.
J'ai eu marre de réécrire toujours le meme code, alors Germain Lib est apparue. 

GermainLib nécessite **Cmake** version **3.14** minimum ou +

commande de creation des liens avec cmake :

    cmake -S . -B build
commande de construction du projet :

    cmake --build build

commande d'execution du projet :

    ./main

La fonction main se trouve dans le dossier apps

Lors de l'importation des includes de la librairie, le chemin commence par :

    germainLib/

**Auteur** : **Antunes Rémi**  (**remi.antunes@isen.yncrea.fr**)

# Sommaire

**Fonctionalité** de la librairie

### Collection
 1. Linked List
 2. Queue
 3. Stack
 4. Quad Tree
 5. Binary Tree

### Tools
 6. Binary Tools
 7. Math

### Type

 8. Integer
 9. Short Integer

### Other
 10. Color
 11. Geometry

## 1. Linked List

**GermainLib** gere les **listes simplement et doublement chainée généralisées**. Avec une implementation propre d'un système d'itération pour le parcours de la liste. L'item contenu dans la liste doit être obligatoire fournit par adresse et alloué en mémoire. 

Les fonctionnalités sur les listes chainée : 

 - ajout d'un item dans la liste chainée 
 - récupération d'un item sans le supprimer de la liste
 - récupération de l'index d'un item dans la liste
 - récupérer un item en le supprimant de la liste chainée
 - suppression d'un item de la liste chainée
 - verification de la présence d'un item dans la liste chainée
 - affichage de l'entièreté de la liste chainée
 - suppression intégrale du contenu de la liste chainée
 - système d'itérations pour parcourir la liste chainée

inclure le header pour les listes simplement chainées

    germainLib/collection/list/simpleLinkedList.h

inclure le header pour les listes doublement chainées

    germainLib/collection/list/doubleLinkedList.h

(propose une panoplie complete sur les listes chainée)

## 2. Queue

**GermainLib** propose un sytème de **queue généralisée**.

Les fonctionnalités de la file d'attente : 

 - ajout d'un élément dans la file d'attente 
 - récupération d'un élément de la file d'attente en le supprimant de la file d'attente
 - visionner  le premier élément de la file d'attente 
 - re-fixer la taille limite de la file d'attente
 - supprimer l'entièreté de la file d'attente

inclure le header pour les files d'attentes

    germainLib/collection/list/queue.h

## 3. Stack

**GermainLib** propose un sytème de **stack généralisée**.

Les fonctionnalités de la pile : 

 - ajout d'un élément dans la pile 
 - récupération d'un élément de la pile en le supprimant en le supprimant de la pile
 - re-fixer la taille limite de la pile
 - 
inclure le header pour les piles 

    germainLib/collection/list/stack.h

## 4. Quad Tree

**GermainLib** propose une panoplie de fonction de base permettant de construire un **Quad Tree généralisé**.

 - creation d'un noeud
 - suppression du quad tree

inclure le header pour les quadTree 

    germainLib/collection/tree/quadtree.h

## 5. Binary Tree

**GermainLib** propose une panoplie de fonction de base permettant de construire un **Binary Tree généralisé**. Optimisé dans le parcours de l'arbre et le système d'insertion afin d'éviter le surchagement de la pile. Deux types de fonctions sont présentent la version récursive et la version itératif.

**En cours de développement**

inclure le header pour les binaryTree 

    germainLib/collection/tree/binaryTree.h

##  6. Binary Tools

Outils nécessaire afin d'effectuer une conversion entre binaire et nombre entier.

## 7. Math

Panoplie de fonction mathématique optimisée machine (rapidité d'execution). 

##  8. Integer

En développement

## 9. Short Integer

En développement

##  10. Color

Outils facilitant le travaille autour des couleurs RGB.

Une partie des fonctions sont dédier pour interagir avec les **Collections** de **Germain Lib**

## 11. Geometry

Outils facilitant le travaille autour des points et des zones rectangulaires.

Une partie des fonctions sont dédier pour interagir avec les **Collections** de **Germain Lib**

# En développement

 - Thread Safe de certaine collection : Queue, Stack et Linked List
 - Liste chainée ordonnée sans répétition d'élément
 - M Ary Tree Dynamique
 - M Ary Tree Statique
 - String Object

## Licence


#### GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
