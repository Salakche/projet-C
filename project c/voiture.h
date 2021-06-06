
typedef struct Voiture
        {
                int idVoiture;
                char marque[15];
                char nomVoiture[15];
                char couleur[7];
                int nbplaces;
                int prixJour;
                char EnLocation[5];

        } car;

typedef struct data_voiture
{
	car vtr;
	struct data_voiture *suivant;
} listevoiture;



void Alert(char *msg)
{
	int i;


	for(i=0;i<2;i++)
	{

		system("cls");
		Sleep(450);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\a\a%s",msg);
		Sleep(450);
	}
}


///*je recherche la voiture et je prend une liste et le ID pour le comparer (si NULL je return 0/****

listevoiture* rech_voiture(listevoiture *l,int idVoiture)
{

	if(l == NULL)
		return NULL;

	if(l->vtr.idVoiture == idVoiture)
			{
			    return l;
			}
	else
		return rech_voiture(l->suivant,idVoiture);

}



///*affichage  des champs du voiture/***

void affichage(listevoiture *aide_vtr)
{
	empty_ui();

	printf("\tIdentifiant               :  %d",aide_vtr->vtr.idVoiture);
	printf("\n\n\t\tMarque              :  %s",aide_vtr->vtr.marque);
	printf("\n\t\tNom                   :  %s",aide_vtr->vtr.nomVoiture);
	printf("\n\t\tCouleur               :  %s",aide_vtr->vtr.couleur);
	printf("\n\t\tNb place              :  %d",aide_vtr->vtr.nbplaces);
	printf("\n\t\tprix par jour         :  %s",aide_vtr->vtr.couleur);
	printf("\n\t\tLocation Statut       :  %s",aide_vtr->vtr.EnLocation);
	printf("\n\n");
	system("pause");

}


///**demandez de saisir les champs d'une voiture puis retourner cet element//****

listevoiture* saisie_voiture()
{


	listevoiture *vtr_fin=NULL;
	car vtr;

	empty_ui();

	vtr_fin=(listevoiture*)malloc(sizeof(listevoiture));

	printf("\n\n\tSaisie les info de la voiture......\n");

	printf("\n\tMarque        :  ");
	scanf("%s",vtr.marque);

	printf("\tNom           :  ");
	scanf("%s",vtr.nomVoiture);

	printf("\n\tId de Voiture :  ");
	scanf("%d",&vtr.idVoiture);

	printf("\n\tCouleur       :  ");
	scanf("%s",vtr.couleur);

	printf("\n\tNb de place :  ");
	scanf("%d",&vtr.nbplaces);

	printf("\n\tPrix par jour :  ");
	scanf("%d",&vtr.prixJour);

    printf("\n\tlocation satut :  ");
    scanf("%s",vtr.EnLocation);

	vtr_fin->vtr=vtr;
	vtr_fin->suivant=NULL;


	return vtr_fin;

}

///***inserez la voiture à la fin de liste de voiture /*

listevoiture* insertion(listevoiture *l,listevoiture *tmp)
{
	listevoiture *p=NULL;

	if ( l == NULL )
		return tmp;

	p=l;
	while(p->suivant!=NULL)
	{
		p=p->suivant;
	}
	p->suivant=tmp;
	return l;
}


///**le fonction recherche puis trouve la voiture et retourne la liste aprés modification/******

listevoiture* modification(listevoiture *l)
{
	listevoiture *modif=NULL;
	int rech_id;

	printf("\n\tDonnee identifiant du Voiture   :  ");
	scanf("%d",&rech_id);

	modif=rech_voiture(l,rech_id);

	if(modif != NULL)
	{
	   empty_ui();
		printf("\n\n\n\t\tRe-saisie des info de la voiture....");
		printf("\n\tMarque        :  ");
        scanf("%s",modif->vtr.marque);

        printf("\tNom           :  ");
        scanf("%s",modif->vtr.nomVoiture);

        printf("\n\tId de Voiture :  ");
        scanf("%d",&modif->vtr.idVoiture);

        printf("\n\tCouleur       :  ");
        scanf("%s",modif->vtr.couleur);

        printf("\n\tNb de place :  ");
        scanf("%d",&modif->vtr.nbplaces);

        printf("\n\tPrix par jour :  ");
        scanf("%d",&modif->vtr.prixJour);

        printf("\n\tlocation satut :  ");
        scanf("%s",modif->vtr.EnLocation);


	}
	else
	Alert("Voiture non trouvee");

	return l;
}


listevoiture* suppression_position(listevoiture *l,listevoiture *supp)**********************
{
	listevoiture *tmp=NULL;********************
	tmp=l;
	while((tmp->suivant!=supp)&&(tmp!=NULL))
		tmp=tmp->suivant;

	if(tmp->suivant==supp)
	{
		tmp->suivant=supp->suivant;
		free(supp);
	}

	return l;
}



///***la fonction recherche la voiture entrée et la supprime et retourne la liste aprés modification/******

listevoiture* suppression_voiture(listevoiture *l)
{
	listevoiture *voiture_supp=NULL;
	int rech_id;

	if( l == NULL)
		Alert("Suppression impossible\n\t\t\t\tPas de voiture en stock");
	else
	{
		printf("\n\t\t\tDonner identifiant de voiture :  ");
		scanf("%d",&rech_id);

		voiture_supp=rech_voiture(l,rech_id);

		if(voiture_supp==NULL)
			Alert("Voiture non trouver");
		else
		{
		    if( strcmp(voiture_supp->vtr.EnLocation,"oui") == 0)
            {
                 Alert("Supprission impossible : voiture alloue");
                 return l;
            }

            else
            {

                 if(l==voiture_supp)
                 {
                     l=l->suivant;
                     free(voiture_supp);
                 }
                 else
                 {
                     l=suppression_position(l,voiture_supp);
                     Alert("Voiture supprimer");
                 }
            }
	     }

	}

	return l;
}



///**la fonction trouve la voiture dans la liste/***

listevoiture* recherche_vtr(listevoiture *t,char *nom)
{

	if(t==NULL)
	return NULL;
	if(strcmp(t->vtr.nomVoiture,nom)==0   &&   strcmp(t->vtr.EnLocation,"non")==0)
		return t;
    if(strcmp(t->vtr.nomVoiture,nom)==0   &&   strcmp(t->vtr.EnLocation,"oui")==0)
        return NULL;
	return recherche_vtr(t->suivant,nom);


}


