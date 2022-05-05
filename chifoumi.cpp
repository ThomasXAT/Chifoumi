/***************************************************************
 * Name:      chifoumi.cpp
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe metier (= module) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODULE ---------------------------

Chifoumi::Chifoumi()
{
    (*this).coupJoueur = rien;
    (*this).coupMachine = rien;
    (*this).scoreJoueur = 0;
    (*this).scoreMachine = 0;
}

Chifoumi::~Chifoumi()
{
    delete [] (this);
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
	return (*this).coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return (*this).coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return (*this).scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return (*this).scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;

    // avant de commencer : match nul
    gagnantARetourner = 'N';

    // il sera modifie dans l'un des cas suivants
    switch (getCoupJoueur())
    {
    case (pierre):
        if (getCoupMachine() == papier)
        {
            gagnantARetourner = 'M';
        }
        else if (getCoupMachine() == ciseau)
        {
            gagnantARetourner = 'J';     
        }
        break;
    
    case (papier):
        if (getCoupMachine() == pierre)
        {
            gagnantARetourner = 'J';
        }
        else if (getCoupMachine() == ciseau)
        {
            gagnantARetourner = 'M';     
        }
        break;

    case (ciseau):
        if (getCoupMachine() == pierre)
        {
            gagnantARetourner = 'M';
        }
        else if (getCoupMachine() == papier)
        {
            gagnantARetourner = 'J';   
        }  
        break;
    }
    return gagnantARetourner;
}

         ///* Methodes utilitaires du Module

int randMinMax(int min, int max){
    /* pre-condition : min<max ;
       Le nbre aleatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur a retourner
    unsigned int nbAleatoire;
    nbAleatoire = randMinMax(0,3);
    switch (nbAleatoire)
    {
    case 1 :
        valeurGeneree = pierre;
        break;
    case 2 :
        valeurGeneree = papier;
        break;
    case 3 :
        valeurGeneree = ciseau;
        break;
    default:
        break;
    }
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    (*this).coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    (*this).coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    (*this).scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    (*this).scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {   
    if (p_gagnant == 'J') 
    {
        setScoreJoueur(getScoreJoueur() + 1);
    }
    else if (p_gagnant == 'M')
    {
        setScoreMachine(getScoreMachine() + 1);
    }
}

void Chifoumi::initScores() {
    setScoreJoueur(0);
    setScoreMachine(0);
}

void Chifoumi::initCoups() {
    setCoupJoueur(rien);
    setCoupMachine(rien);
}
