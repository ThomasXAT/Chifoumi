/***************************************************************
 * Name:      ChifoumiJeu.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe metier (= Module) ChifoumiJeu-v1
 **************************************************************/
#ifndef CHIFOUMIJEU_H
#define CHIFOUMIJEU_H
#include <iostream>

using namespace std;

class ChifoumiJeu
{
    ///* ---- PARTIE MODULE ---------------------------

public:
    ///* Une definition de type enumere
    enum UnCoup {pierre, papier, ciseau, rien};

    ///* Methodes du Module
public:
    ChifoumiJeu();
    virtual ~ChifoumiJeu();

    // Getters
    UnCoup getCoupJoueur();
    /* retourne le dernier coup joue par le joueur */
    UnCoup getCoupMachine();
    /* retourne le dernier coup joue par le joueur */
    unsigned int getScoreJoueur();
    /* retourne le score du joueur */
    unsigned int getScoreMachine();
    /* retourne le score de la machine */
    char determinerGagnant();
    /* determine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
               en fonction du dernier coup joue par chacun d'eux */
    UnCoup genererUnCoup();
    /* retourne une valeur aleatoire = pierre, papier ou ciseau.
       Utilisee pour faire jouer la machine */

    ///* Methodes utilitaires du Module
private :



    // Setters
public:
    void setCoupJoueur(UnCoup p_coup);
    /* initialise l'attribut coupJoueur avec la valeur
               du parametre p_coup */
    void setCoupMachine(UnCoup p_coup);
    /* initialise l'attribut coupmachine avec la valeur
               du parametre p_coup */
    void setScoreJoueur(unsigned int p_score);
    /* initialise l'attribut scoreJoueur avec la valeur
               du parametre p_score */
    void setScoreMachine(unsigned int p_score);
    /* initialise l'attribut coupMachine avec la valeur
               du parametre p_score */


    // Autres modificateurs
    void majScores(char p_gagnant);
    /* Mise a jour des scores en fonction des regles de gestion actuelles :
                - 1 point pour le gagnant lorsqu'il y a un gagnant
                - 0 point en cas de match nul
            */
    void initScores();
    /* initialise a 0 les attributs scoreJoueur et scoreMachine
               NON indispensable */
    void initCoups();
    /* initialise a rien les attributs coupJoueur et coupMachine
               NON indispensable */


    ///* Attributs du Module
private:
    unsigned int scoreJoueur;   // score actuel du joueur
    unsigned int scoreMachine;  // score actuel de la Machine
    UnCoup coupJoueur;          // dernier coup joue par le joueur
    UnCoup coupMachine;         // dernier coup joue par la machine
};

#endif // CHIFOUMIJEU_H
