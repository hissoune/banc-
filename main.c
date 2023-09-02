#include <stdio.h>
#include <stdlib.h>
#define cmax 20
 int choix,x;
typedef struct SClient
{
    int code_cli;
    char nome[cmax];
    char prenome[cmax];
}SClient;
typedef struct dat
{
    int jour;
    int moin;
    int anne;
}dat;
typedef struct SCompte
{
   int code_com;
   int code_cli;
   struct dat date;
}SCompte;

 SClient clients[];
SCompte comptes[];

void menu()
{
    printf("1.gestion de client : \n");
    printf("2.gestion de compte : \n");
    printf("3.gestion des operation : \n");
    printf("4.quiter le programe : \n");
    printf("5.retoure: \n");
    printf("votre choix  : ");
    scanf("%d",&choix);
    sous_menu(choix);
}
void sous_menu(int a)
{
    if(a==1)
    {
        printf("1.ajouter\n" );
        printf("2.modifier\n" );
        printf("3.suprimer\n" );
        printf("4.aficher\n" );
        printf("5.retout\n" );
        printf("choizire un sous menu : " );
        scanf("%d",&x);
        gerer_client(x);
    }
    else if (a==2)
    {
         printf("1.ajouter" );
        printf("2.rechercher\n" );
        printf("3.aficher la liste\n" );
        printf("4.suprimer\n" );
        printf("5.retout\n" );
        printf("choizire un sous menu :" );
        scanf("%d",&x);
        //gerer_compte(x);

    }
    else if (a==3)
    {
         printf("1.retreat\n" );
        printf("2.aficher apres des operations\n" );
        printf("3.retour\n" );
         printf("choizire un sous menu :" );
        scanf("%d",&x);
        //gerer_operation(x);
    }else if (a==4)
    {
        return 0 ;
    }else printf("movaix choix");

}
void gerer_client(int a)
{
    if(a==1)
    {
       struct SClient client;
       FILE * file;
        printf("code de client : ");
        scanf("%d",&client.code_cli);
        printf("le nome : ");
        scanf("%s",&client.nome);
        printf("le prenome : ");
        scanf("%s",&client.prenome);
        file=fopen("client.txt","a");
        fwrite(&client,sizeof(client),1,file);
        if(fwrite!=0)
            printf("ajouter avec sucsecs ");
        else printf("error");
        fclose(file);
    } else if(a==2)
    {
        struct SClient client;
        struct SClient nvClient;
        FILE *file;
        printf("donner le code a modifier : ");
        scanf("%d",&nvClient.code_cli);
        printf(" nouveau nome : ");
        scanf("%s",&nvClient.nome);
        printf("nv prenome : ");
        scanf("%s",&nvClient.prenome);
        file=fopen("client.txt","r");
        int nbClients=0;
          while(fread(&client,sizeof(struct SClient),1,file)){
            clients[nbClients]=client;
            nbClients++;
          }fclose(file);
          remove("client.txt");
          FILE *nf;
          nf=fopen("nv.txt","a");
          for(int i=0;i<nbClients;i++)
          {
              if(clients[i].code_cli==nvClient.code_cli)
              fwrite(&nvClient,sizeof(clients[i]),1,nf);
              else
                fwrite(&clients[i],sizeof(clients[i]),1,nf);
              }fclose(nf);
              rename("nv.txt","client.txt");}
              else if (a==3)
              {

        struct SClient client;
        int code;
        FILE *file;
        printf("donner le code a suprimer: ");
        scanf("%d",&code);
        file=fopen("client.txt","r");
        int nbClients=0;
          while(fread(&client,sizeof(struct SClient),1,file)){
            clients[nbClients]=client;
            nbClients++;
          }fclose(file);
          remove("client.txt");
          FILE *nf;
          nf=fopen("nv.txt","a");
          for(int i=0;i<nbClients;i++)
          {
              if(clients[i].code_cli!=code)
                fwrite(&clients[i],sizeof(clients[i]),1,nf);
              }fclose(nf);
              rename("nv.txt","client.txt");
              }
    else if (a==4)
    {
        FILE *file;
        struct SClient client;
        file=fopen("client.txt","r");
        int nbClients=0;
        while(fread(&client,sizeof(struct SClient),1,file)){
            clients[nbClients]=client;
            nbClients++;
        }
        fclose(file);
        for(int c=0;c<nbClients;c++)
        {
          printf("le code : %d\n",clients[c].code_cli);
          printf(" nome  %s | %s\n",clients[c].nome,clients[c].prenome);}
    }
    else if(a==5)
          menu();
}

int main()
{
    menu();

    return 0;
}
