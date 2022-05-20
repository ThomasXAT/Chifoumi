/***************************************************************
 * Name:      ChifoumiJeu.cpp
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe metier (= module) ChifoumiJeu-v1
 **************************************************************/
#include "ChifoumiJeu.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODULE ---------------------------

ChifoumiJeu::ChifoumiJeu()
{
    (*this).coupJoueur = rien;
    (*this).coupMachine = rien;
    (*this).scoreJoueur = 0;
    (*this).scoreMachine = 0;
}

ChifoumiJeu::~ChifoumiJeu()
{
    delete [] (this);
}

        /// Getters

ChifoumiJeu::UnCoup ChifoumiJeu::getCoupJoueur() {
    return (*this).coupJoueur;
}

ChifoumiJeu::UnCoup ChifoumiJeu::getCoupMachine() {
    return (*this).coupMachine;
}

unsigned int ChifoumiJeu::getScoreJoueur() {
    return (*this).scoreJoueur;
}

unsigned int ChifoumiJeu::getScoreMachine() {
    return (*this).scoreMachine;
}

char ChifoumiJeu::determinerGagnant()
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

ChifoumiJeu::UnCoup ChifoumiJeu::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur a retourner
    unsigned int nbAleatoire;
    nbAleatoire = randMinMax(1,4);
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

void ChifoumiJeu::setCoupJoueur(UnCoup p_coup) {
    (*this).coupJoueur = p_coup;
}

void ChifoumiJeu::setCoupMachine(UnCoup p_coup) {
    (*this).coupMachine = p_coup;
}

void ChifoumiJeu::setScoreJoueur(unsigned int p_score) {
    (*this).scoreJoueur = p_score;
}

void ChifoumiJeu::setScoreMachine(unsigned int p_score) {
    (*this).scoreMachine = p_score;
}

void ChifoumiJeu::majScores(char p_gagnant) {
    if (p_gagnant == 'J')
    {
        setScoreJoueur(getScoreJoueur() + 1);
    }
    else if (p_gagnant == 'M')
    {
        setScoreMachine(getScoreMachine() + 1);
    }
}

void ChifoumiJeu::initScores() {
    setScoreJoueur(0);
    setScoreMachine(0);
}

void ChifoumiJeu::initCoups() {
    setCoupJoueur(rien);
    setCoupMachine(rien);
}
