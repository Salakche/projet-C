#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include "voiture.h"
#include "client.h"
#include "contrat.h"
#include "menu.h"
#include "save.h"



int main()
{

    char nom[20],prenom[20],nom_1[20];

	listevoiture *vtrr=NULL,*unev=NULL,*status_car=NULL;
	listecln *clnts=NULL,*cln=NULL;
	listectr *cntrs=NULL,*cntr=NULL;
	int choix_premier=0,choix_second=0,choix,help;


    vtrr=chargement_Voiture("voiture.txt");
	clnts=chargement_Client("client.txt");
	cntrs=chargement_Contrat("contrat.txt");




while((choix_second!=27)&&(choix_premier!=9))
{
    choix_premier=MenuPrincipal();
    switch(choix_premier)
  {

   ///******************MENU LOCATION******************///

    case 1:

        while(choix_second!=27)
		{
		    choix_second=MenuLocation();

		    ///************AFFICHAGE CONTRAT**************///

			if(choix_second==49)
			{
               printf("\n\n\t\t\tUn contrat(1)\ttous contrats(2)\n\t\t\t\t\t");
               choix=getch();
                if(choix==49)
				{
					cntr=rechercher_ctr(cntrs);
					if(cntr==NULL)
						Alert("Contrat non-trouvee");
					else
						affichagee(cntr);
				}

				if(choix==50)
				{
					cntr=cntrs;
					if(cntr==NULL)
						Alert("Pas De Contrat");
					else
                    {
                        while(cntr!=NULL)
                        {
                          affichagee(cntr);
                          cntr=cntr->suivant;
                        }
                    }
                    getch();
				}
			}
             ///****************LOUER UNE VOITURE***************///
			if(choix_second==50)
			{

				printf("\n\n\t\tvous etes deja un client oui(o)/non(n) : ");
				do
				{
                    choix=getch();
				}while((choix!=111)&&(choix!=110));

				///*** si le client existe

                if(choix==111)
				{
					empty_ui();

					printf("\n\n\tverefication de vos info...");
					printf("\n\n\t\tNom       : ");
					scanf("%s",nom_1);
					printf("\n\n\t\tPrenom    : ");
					scanf("%s",prenom);
					printf("\n\n\t\tNom Voiture: ");
					scanf("%s",nom);
					status_car=recherche_vtr(vtrr,nom);
					if(status_car != NULL )
                    {
                        Alert("Voiture Libre");
                        cln=rechercher_cln(clnts,nom_1,prenom);
                        if(cln==NULL)
                        {
                           Alert("Client non-trouve\n\n\t\t\t\tsaisir ses information");
                           getch();
                           cln=saisitionn();
                           clnts=insertion_fin(clnts,cln);
                           cntr=saisition(status_car,cln);
                           cntr->suivant=cntrs;
                           cntrs=cntr;
                           Alert("Location effectuee");
                        }
                        else
                        {
                           Alert("Client trouve");
                           cntr=saisition(status_car,cln);
                           cntr->suivant=cntrs;
                           cntrs=cntr;
                           Alert("Location effectuee");
                        }
                    }
                    else
                    {
                           Alert("Voiture n est pas disponible");

                    }
			     }

			     if(choix==110 )
                 {
                    empty_ui();
                    printf("\n\n\t\tNom Voiture: ");
                    scanf("%s",nom);
                    status_car=recherche_vtr(vtrr,nom);
                    if(status_car != NULL )
                    {
                           Alert("saisir les information du client");
                           //getch();
                           cln=saisitionn();
                           clnts=insertion_fin(clnts,cln);
                           cntr=saisition(status_car,cln);
                           cntr->suivant=cntrs;
                           cntrs=cntr;
                           Alert("Location effectuee");

                    }
                    else
                    {
                           Alert("Voiture n est pas disponible");
                    }
                 }
			}

			if(choix_second==51)
				  cntrs=Retour_Contrat(cntrs,vtrr);


			if(choix_second==52)
				  cntrs=modificationn(cntrs);


			if(choix_second==53)
			{
				  cntr=rechercher_ctr(cntrs);
				  if(cntr==NULL)
                  Alert("Contrat non-trouvee");
				  else
                  {
					    cntrs=suppressionn(cntrs,cntr,vtrr);
					    Alert("Contrat supprimer");
				  }
			}

			if(choix_second==57)
				  choix_second=27;
		}

        Sauvgarde(1,&vtrr,&clnts,&ctrs);
        choix_second=0;
        break;


   ///*******************MENU VOITURE*******************///


    case 2:


        while(choix_second!=27)
        {
			choix_second=MenuGestionVoiture();
                       ///affichage des Voitures
			if(choix_second==49)
			{
			       printf("\n\n\t\t\tUne Voiture(1)\tTous les Voitures(2)\n\t\t\t\t\t");
                       ///affichage une voiture
                   if(getch()==49)
                   {
                         empty_ui();
						 printf("\n\n\t\tVoiture recherchee...");
						 printf("\n\n\t\tId de voiture   :  ");
						 scanf("%d",&help);
                         unev=rech_voiture(vtrr,help);
						 if(unev == NULL)
							 Alert("Voiture non-trouvee");
						 else
                         {
                             Alert("Voiture trouvee");
                             //printf("\n\t\tMarque : %s\n\t\tNom : %s\n\t\tPrix par jour : %d\n\t\tLocation-statut : %s ",typ->vtr.marque,typ->vtr.nomVoiture,typ->vtr.prixJour,typ->vtr.EnLocation);
                             affichage(unev);
                         }
					}
                        ///affichage tout les Voiture
					if(getch()==50)
					{
                         unev=vtrr;
					     if(unev == NULL)
							 Alert("Pas De Voiture");
                         else
                         {
                                empty_ui();
                                while(unev !=NULL)
                                {
                                    affichage(unev);
                                    unev=unev->suivant;
                                }
                         }
                         getch();
                    }
               }

                                 ///ajoute des voitures
               if(choix_second==50)
			   {
					 printf("\n\n\t\tVoiture (1)\t\tplusieurs Voitures (2)\n\t\t");
                     do
                      {
                       choix=getch();
                      }while( (choix!=49) && (choix!=50) );

                             ///ajoute une voiture
                     if(choix==49)
                     {
                            unev=saisie_voiture();
                            vtrr=insertion(vtrr,unev);
                            Alert("voiture enregistrer");
                     }

                            ///ajoute plusieurs voitures

                     if(choix==50)
                     {
                            printf("\n\n\t\tsaisr le nombre des Voiture : ");
                            scanf("%d",&help);
                            int i=0;
                            while(i<help)
                            {
                                unev=saisie_voiture();
                                vtrr=insertion(vtrr,unev);
                                i++;
                            }
                            Alert("enregistrement Voiture effectuer");
                     }
			   }

                         ///modifier info des voitures

			   if(choix_second==51)
				     vtrr=modification(vtrr);

                        ///supprission d une voiture

               if(choix_second==52)
			         vtrr=suppression_voiture(vtrr);

                        ///RETOUR==>quitter le menu zt enregistrer

			   if(choix_second==57)
                     choix_second=27;
		}

		Sauvgarde(2,&vtrr,&clnts,&cntrs);
		choix_second=0;
		break;

    	case 3:


             ///***********MENU CLIENT**************///

		while(choix_second!=27)
		{
			choix_second=MenuGestionClient();
			     ///***********AFFICHAGE CLIENTS*********///

            if(choix_second==49)
			{

                printf("\n\n\t\t\tUn client(1)\t\tTous clients(2)\n\n\t\t\t\t\t");
				choix=getch();
                ///**********affichage un client**********//
				if(choix==49)
				    {
                           empty_ui();
                            printf("\n\n\tClient ....");
                            printf("\n\t\tNom          : ");
                            scanf("%s",nom);
                            printf("\n\t\tPrenom       : ");
                            scanf("%s",prenom);
                            cln=rechercher_cln(clnts,nom,prenom);
                            if(cln==NULL)
                                 {
                                    Alert("Client non-trouver");
                                 }
                            else
                                 {
                                    Alert("Client trouver");
                                    affichageee(cln);
                                 }
                            getch();
				    }

                 ///**********affichage tous les clients**********//

				if(choix==50)
				{
                            cln=clnts;
                            if(cln==NULL)
                               Alert("Pas de Client");
                             else{
                                    empty_ui();
                                    while(cln!=NULL)
                                        {
                                           affichageee(cln);
                                           cln=cln->suivant;
                                        }
                                     getch();
					             }
				}
			}


                       ///**********AJOUTE CLIENT**********//

			if(choix_second==50)
			  {

                 cln=saisitionn();
                 clnts=insertion_fin(clnts,cln);

			  }

			           ///**********MODIFIER CLIENT**********//

			if(choix_second==51)
			  {
				 clnts=modificationnn(clnts);
			  }

			           ///**********SUPPRIMER CLIENT**********//

			if(choix_second==52)
			  {
				//les_clients=supprimer_Client(les_clients);
			     clnts=suppressionnn(clnts,&cntrs,vtrr);
			  }

			           ///**********QUITTER MENU CLIENT**********//

			if(choix_second==57)
		       {
				 choix_second=27;
               }
		}

		             ///***********Enregistrer Modification********//

        Sauvgarde(3,&vtrr,&clnts,&cntrs);
		choix_second=0;

		break;


		case 9:
		   break;

}
}


Sauvgarde(0,&vtrr,&clnts,&cntrs);
return 0;




}
