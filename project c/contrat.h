typedef struct {char dt[12];} date;


typedef struct{

            float numContrat;
            int idVoiture;
            int idClient;
            date debut;
            date fin;
            int coute;

              } ctr;

typedef struct data_Contrat{
	ctr contra;
	struct data_Contrat *suivant;
} listectr;







///***cette fcnt cherche un contrat celon le id de voiture,le nom et le prénom du client/******

listectr* rechercher_ctr(listectr *l)
{
	listectr *aide=NULL;
	int Id;
	float num;

	printf("\n\tId de voiture louee   :  ");
	scanf("%d",&Id);
	printf("\n\tNum du contrat        :  ");
	scanf("%f",&num);
	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
			if(aide->contra.numContrat == num)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}





///****affichage du contrat/****


void affichagee(listectr *crt)
{
	empty_ui();

	printf("\n\tN\xf8 du contrat   :  %.0f\n------------------------------\n",crt->contra.numContrat);

	printf("\n\n\tId Voiture         :  %d",crt->contra.idVoiture);
	printf("\n\n\tId Client            :  %d",crt->contra.idClient);

	printf("\n\n\tDebut              :  %s",crt->contra.debut.dt);
	printf("\n\n\tFin                :  %s",crt->contra.fin.dt);

	printf("\n\n\tCout location      :   %d TTC",crt->contra.coute);

	printf("\n\n");

   getch();
}

///**saisir des champs du contrat/*****


listectr* saisition(liste_vtr *l,liste_client *t)
{
    listectr *aide=NULL;

	empty_ui();
	aide=(listectr*)malloc(sizeof (listectr) );
    printf("\n\tsaisir un code contrat :");
    scanf("%f",&aide->contra.numContrat);

	aide->contra.idVoiture=l->vtr.idVoiture;
	aide->contra.idClient=t->individu.idClient;

	printf("\n\tNumero contrat : %.0f",aide->contra.numContrat);

    printf("\n\tDate du debut    :  ");
    scanf("%s",aide->contra.debut.dt);

    printf("\n\tDate retour      :  ");
    scanf("%s",aide->contra.fin.dt);

	printf("\n\tnombre jour      : ");
	scanf("%d",&aide->contra.coute);

	aide->contra.coute=(aide->contra.coute)*(l->vtr.prixJour);
	strcpy(l->vtr.EnLocation,"oui");

	return aide;

}




///*la suppression de la contrat /***


listectr* suppressionn(listectr *l,listectr *supp,liste_vtr *t)
{
	listectr *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		l=l->suivant;
	    free(supp);
	    return l;
	}


	parc=l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		parc->suivant=supp->suivant;
		free(supp);
	}

	return l;

}





///**cette fcnt permet de completer les champs d'un  contrat lors du retour de la véhicule louée(calcul du prix total de location) **/******


listectr* Retour_Contrat(listectr *l,liste_vtr *t)
{
	listectr *contr=NULL;

	empty_ui();

	contr=rechercher_ctr(l);

	if(contr==NULL)
		{Alert("Contrat non-trouve");return l;}

	else
	{

		printf("\n\tContrat numero   :  %.0f",contr->contra.numContrat);
		printf("\n\tCout    :  %d\n\n",contr->contra.coute);
		l=suppressionn(l,contr,t);
        Alert("Contrat supprimer");
	}
	Alert("statut de la voiture est change.");
    return l;

	//getch();
}



///****modifier une contrat au cas d'existance/****

listectr* modificationn(listectr *l)
{
	listectr*rech=NULL;

	if(l==NULL)
            {
                Alert("Pas de contrat disponible");
                return l;
            }

	rech=rechercher_ctr(l);

	if(rech==NULL)
            {
                Alert("Contrat non-trouve");
                return l;
            }

///**************RE-SAISIE DU CONTRAT*****************

     Alert("Contrat trouvee.");
     printf("\n\tDate du debut    :  ");
     scanf("%s",rech->contra.debut.dt);
     printf("\n\tDate retour      :  ");
     scanf("%s",rech->contra.fin.dt);
     Alert("Contrat modifie");
	 return l;

}





///------------------------------------------------------------------------------------------------------------


///****une fonction qui renvoit un contrat/****






int listectr* recherche_id(listectr *l,int Id)
{
	listectr *aide=NULL;

	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}








void suppression_contrat_id(listectr **l,listectr *supp,liste_vtr *t)
{
	listectr *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==*l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		*l=(*l)->suivant;
	    free(supp);
	    return;
	}


	parc=*l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		parc->suivant=supp->suivant;
		free(supp);
	}

	return;

}

