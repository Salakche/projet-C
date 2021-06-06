

typedef struct{

            int idClient;
            char nom[20];
            char prenom[20];
            int cin;
            char adresse[25];
            int telephone;

              } client;

typedef struct data_client
{
	client individu;
	struct data_client *suivant;
} listecln;



///****rechercher les client par comparer ses com et prenom//********


listecln* rechercher_cln(listecln *l,char *nom,char *prenom)
{


	while(l!=NULL)
		{
			if(strcmp(l->individu.nom,nom)==0 && strcmp(l->individu.prenom,prenom)==0)
				   {return l;}

          l=l->suivant;
		}

 	return NULL;

}


listecln* rechercher_cln_supp(listecln *l,char *nom,char *prenom)
{
   if(strcmp(l->individu.nom,nom)==0 && strcmp(l->individu.prenom,prenom)==0)
				   {return l;}


	while(l->suivant!=NULL )
		{
			if(strcmp((l->suivant)->individu.nom,nom)==0 && strcmp((l->suivant)->individu.prenom,prenom)==0)
				   {return l;}

          l=l->suivant;
		}

 	return NULL;

}


///****affcihage d'un client/***************
void affichageee(listecln *t)
{

	printf("\n\tNom          : %s",t->individu.nom);
	printf("\t\tPrenom         : %s",t->individu.prenom);
    printf("\n\tId         : %d",t->individu.idClient);
	printf("\n\tCIN          : %d",t->individu.cin);
    printf("\n\tNum telephone: %d",t->individu.telephone);

    printf("\n\tAdresse         : %s",t->individu.adresse);

    printf("\n\n\n");

}



///***saisir les champs d'un client/**********



listecln* saisitionn()
{
	client aide_client;
    listecln *outpt=NULL;

	empty_ui();

	outpt=(listecln*)malloc(sizeof(listecln));

          ///****SAISIE DU CLIENT*****

	printf("\nSaisie les info du client........");

	printf("\n\t\tNom           : ");
	scanf("%s",aide_client.nom);

	printf("\n\t\tPrenom        : ");
	scanf("%s",aide_client.prenom);

	printf("\n\t\tId           : ");
	scanf("%d",&aide_client.idClient);

	printf("\n\t\tN° telephone  : ");
	scanf("%d",&aide_client.telephone);

	printf("\n\t\tNum. CIN      : ");
	scanf("%d",&aide_client.cin);

	printf("\n\t\tAdresse        : ");
	scanf("%s",aide_client.adresse);

	   ///****INITIALISATION DE  DATA_CLIENT****
	outpt->individu=aide_client;
	outpt->suivant=NULL;

	return outpt;
}


///****inserer un client à la fin de la liste/*******



listecln* insertion_fin(listecln *l,listecln *push)
{
	listecln *aide=NULL;


	if(l==NULL)
	{
		push->suivant=NULL;
		l=push;
		return l;
	}
	else
	{
	    aide=l;
		while(aide->suivant!=NULL)
			aide=aide->suivant;

		aide->suivant=push;
		push->suivant=NULL;
	}

	return l;
}



///****modifier un client s'il existe/********

listecln* modificationnn(listecln *l)
{
	listecln *modif_client=NULL,*enreg=NULL;
	char nom[20],prenom[20];

	if(l==NULL)
    {
        Alert("Pas de client");
		getch();
    }
	else
	{
		printf("\n\t\tNom    ( \x22 quitter \x22 pour annuler) :  ");
		scanf("%s",nom);

		if(strcmp(nom,"quitter")!=0)
		{
			printf("\n\t\tPrenom ( \x22 quitter \x22 pour annuler) :  ");
			scanf("%s",prenom);
		}

		if( (strcmp(prenom,"quitter") != 0 ) && (strcmp(nom,"quitter") != 0 ) )
		{
			modif_client=rechercher_cln(l,nom,prenom);
            if(modif_client==NULL)
				Alert("Client non trouve");
			else
			{
				enreg=modif_client;
				modif_client=saisitionn();
				enreg->individu=modif_client->individu;
				free(modif_client);
				Alert("Client modifie");
				return l;
			}
		}
	}
	Alert("Modification anullee.");
	//getch();

	return l;
}



///**suppression d'un client//********


listecln* suppressionnn(listecln *t)
{
	listecln *client_supp_avant=NULL,*aide=NULL;
	char nom[20],prenom[20];



	if(t==NULL)
		Alert("Pas de client");
	else
	{
		printf("\n\t\tNom    ( \x22 quitter \x22 pour annuler) :  ");
		scanf("%s",nom);
		if(strcmp(nom,"quitter")!=0)
		{
			printf("\n\t\tPrenom    ( \x22 quitter \x22 pour annuler) :  ");
			scanf("%s",prenom);
		}
		if(strcmp(nom,"quitter")==0 || strcmp(prenom,"quitter")==0 )
        {
            Alert("supprision anullee");
            return t;
        }

			client_supp_avant=rechercher_cln_supp(t,nom,prenom);
			if(client_supp_avant!=NULL)
			{
				if(client_supp_avant->individu.idClient == t->individu.idClient)
				{
					t=t->suivant;
                    free(client_supp_avant);
					Alert("Client supprime");
					return t;
				}

				else
					{
						aide=(client_supp_avant->suivant)->suivant;
                        free(client_supp_avant->suivant);
                        client_supp_avant->suivant=aide;
						Alert("Client supprime");
						return t;
					}
			}
			else
				Alert("Client non trouve");

	}

	return t;

}







