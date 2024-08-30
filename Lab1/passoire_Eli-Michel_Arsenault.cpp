//#define _CRT_SECURE_NO_WARNINGS //Force le programme a ne pas utiliser une version sécuritaire des librarie 
//CORRECTION: retirer le define

#include <string>
#include <fstream>
#include <iostream> // ajoue pour les input output


#define SIZE 64
//Nous permet d'avoir une longeur predefinie pour notre fichier IMPORTANT de savoir qu'il reste tout de meme un risque si le nombre de caractere pour le fichier depasse 64

using namespace std;



int main(int argc, char* argv[])//Ne pas faire passer c'est instruction en inviter de commande 
{
	//CONSEQUENCE le  risque est que le programme est dependant des arguments et si non remplis risque de plantage


	/*int pansDeCloture{stoi(argv[1])};
	float montantAPayer { stof(argv[2])};*/

	const size_t limite{ SIZE };
	int pansDeCloture{ 0 };
	float montantAPayer{ 0 };

	cout << "Veuillez Entrer votre pas de cloture";
	cin >> pansDeCloture;

	cout << "Veuillez Entrer le montant a payer";
	cin >> montantAPayer;

	float coutParPan {montantAPayer / pansDeCloture};

	// Poteaux nécessaires pour faire une clôture en ligne droite
	int poteaux {pansDeCloture};
	montantAPayer += poteaux * 5;

	/*char nomFichier[10];*/
	//Risque si le fichier entrer est plus gros que 10 caracterer
	//CONSEQUENCE comme marquer en haut, si limite de charactere depasser risque de fuite
	char nomFichier[limite];//CORRECTION augmenter la limite


	/*strcpy(nomFichier, argv[3]);*/
	// Ne prend pas en compte les BOF de plus si aucun n'argument est rentrer en commande ou encore l'argument est plus grand que la limite permise par le char
	// De plus, strcpy n'est pas sécuritaire car si limite depasser on se retrouve dans d'autre parti du code
	//CONSEQUENCE possibilité de faille ou plantage

	bool ficValide{ true };
	cout << "Veuillez Entrer le le nom du fichier a crée ";
	cin >> nomFichier;
	if (strlen(nomFichier) > 62)
	{
		ficValide = false;
		cout << "Nom de fichier trop long veuillez ressaier ";
		do {
			cout << "Veuillez Entrer le le nom du fichier a fabriquer ";
			cin >> nomFichier;
			if (strlen(nomFichier) < 62) {
				ficValide = true;
			}


		} while (ficValide != true);
	}
	//CORRECTION demander a l'utilisateur le nom qu'il veut au lieu de le mettre en commande

	/*strcat(nomFichier, ".exe");*/

	snprintf(nomFichier, strlen(nomFichier), ".exe");
	ofstream fichier {nomFichier};
	fichier << argv[4];

	const char * msg {argv[4]}; //Malgré le fauit que se soit un const, il y a rique que on peut tout de meme ovewright les donnes ce qui pourrait amener un risque
	/*printf(msg, pansDeCloture, coutParPan);*/ //N'est pas sécuritaire, devrait utiliser sprintf
	cout << msg, pansDeCloture, coutParPan;
	/*const char* commande{argv[5]};
	system(commande);*/ 
	// Ici le risque est que la commande system() sert a lancer un programme donc si une personne malveillante metterait en argumant de commande un programme malfesant il pourrait le faire lancer a partir de cette ligne
	//CORRECTION retirer la ligne
}