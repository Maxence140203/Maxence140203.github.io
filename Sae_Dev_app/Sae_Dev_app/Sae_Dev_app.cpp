#include "SAE_Datas_Heat.h"
#include "Traitement.h"
#include <stdlib.h>
#define NOMINMAX
#include <Windows.h>
#include <tchar.h>
#include <chrono>
#define LIBGRAPH2_LEVEL 4
#include <LibGraph2.h>
using namespace LibGraph2;

#include <iostream>
using namespace std;

int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //Affiche la fenêtre graphique avec une taille par défaut
    ILibGraph2* pLibgraph = GetLibGraph2();

    // Taille fenetre
    float size_width = 1000;
    float size_height = 800;

    pLibgraph->show(CSize{ size_width, size_height });

    //Boucle principale d'événements
    evt e;
    bool bShowDisk = true;
    auto tpStartBounce = chrono::high_resolution_clock::now();
    string strAnnee;

    // VARIABLES POUR AFFICHER LES ANNEES EN DESSOUS DE LA COURBE
    int annee = 1992;
    float pointX = 20;
    float pointY = size_width - 50;

    float xCourbe = 60;

    float addPixelX = 50;
    float addPixelY = size_height - 80;

    float margeHaute = 40;
    float margeGauche = 50;

    int compteur;

	SAE_Datas_Heat myStations;
    vector<float> TMoy_Mois = myStations.GetTMoyChaqueMois();
	vector<float> TMin_Mois = myStations.GetTMinChaqueMois();
	vector<float> TMax_Mois = myStations.GetTMaxChaqueMois();

    while (pLibgraph->waitForEvent(e))
    {
        switch (e.type)  //En fonction du type du dernier événement
        {
        case evt_type::evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
          //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
            pLibgraph->beginPaint();





            //Utiliser ici les fonctions de dessins
            //Choisit un stylo rouge d'épaisseur 5 pixels traçant des pointillés
            pLibgraph->setPen(MakeARGB(0, 0, 0, 0), 4.0f, LibGraph2::pen_DashStyles::Dash);
            //Choisit un pinceau jaune
            pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
            //Dessine un rectangle avec le stylo et le pinceau sélectionné
            pLibgraph->drawRectangle(CRectangle{ CPoint{50, 40}, CSize{5, size_height - 94} });
            pLibgraph->drawRectangle(CRectangle{ CPoint{50, size_height - 56}, CSize{size_height + 100, 5} });
            //Choisit un pinceau cyan translucide




            pLibgraph->setPen(MakeARGB(255, 0, 0, 0), 5.0f, LibGraph2::pen_DashStyles::Solid);


            strAnnee = to_string(1992);
            pLibgraph->setFont(CString("Consolas"), 14, FontStyleRegular);

            // Date début fin - Courbe X
            pLibgraph->drawString("1992", CPoint{ margeHaute, size_height - margeGauche });
            pLibgraph->drawString("2021", CPoint{ size_width - 90, size_height - 50 });
            pLibgraph->drawString("2002", CPoint{ margeHaute+260, size_height - margeGauche });
            pLibgraph->drawString("2012", CPoint{ margeHaute + 560, size_height - margeGauche });
             

            // Température Min Max - Courbe Y
            pLibgraph->drawString("-50", CPoint{ 0, size_height - 65 });
            pLibgraph->drawString("0", CPoint{ 15, size_height / 2 - margeHaute + 40});
            pLibgraph->drawString("50", CPoint{ 10, 30 });
            pLibgraph->drawString("25", CPoint{ 15, size_height / 4 - margeHaute + 40 });
            pLibgraph->drawString("-25", CPoint{ 15, size_height - 200 });



            // Tirets pour la courbe des températures
            for (int i = 0; i < 20; ++i)
            {
                pLibgraph->drawString("-", CPoint{ addPixelX, addPixelY - 20 });
                addPixelY += 37;
            }

            // Tirets pour la courbe des dates
            for (int i = 0; i < 30; ++i)
            {
                pLibgraph->drawString("|", CPoint{ addPixelX - 6, addPixelY - 62 });
                addPixelX += 30;
            }
            addPixelX = 50;
            addPixelY = 50;
			

            compteur = 0;
            float moyenne = 0;
            vector<float> tab;

            for (int i = 1; i < TMoy_Mois.size(); i++)
            {
                pLibgraph->setPen(MakeARGB(255, 0, 0, 0), 1.0f, LibGraph2::pen_DashStyles::Solid);
                pLibgraph->drawLine(CPoint{ xCourbe, ((100 - (TMoy_Mois[i - 1] + 50)) / 100) * (800 - margeHaute) }, CPoint{ xCourbe + 2.5f, ((100 - (TMoy_Mois[i] + 50)) / 100) * (800 - margeHaute) });
                xCourbe += 2.5;

                // Recup et ajout des valeur dans la variable
                moyenne += TMoy_Mois[i];
                if (compteur == 12)
                {
                    moyenne /= 12;
                    compteur = 0;
                    tab.push_back(moyenne);
                }
                compteur++;
            }
            xCourbe = 60;
            moyenne = 0;
            compteur = 0;

			
            // Boucle pour afficher la moyenne des années
            for (float i = 1; i < tab.size(); i++)
            {
                pLibgraph->setPen(MakeARGB(255, 0, 255, 0), 3.0f, LibGraph2::pen_DashStyles::Solid);
                pLibgraph->drawLine(CPoint{ 900 / 30 * i + 50, ((100 - (tab[i - 1] + 50)) / 100) * (800 - margeHaute) }, CPoint{ (900 / 30 * (i + 1) + 2.5f) + 50, ((100 - (tab[i] + 50)) / 100) * (800 - margeHaute) });
                xCourbe += 2.5;
            }
            xCourbe = 60;
			
            for (size_t i = 1; i < TMin_Mois.size(); i++)
            {
                pLibgraph->setPen(MakeARGB(255, 0, 0, 255), 1.0f, LibGraph2::pen_DashStyles::Solid);
                pLibgraph->drawLine(CPoint{ xCourbe, ((100 - (TMin_Mois[i - 1] + 50)) / 100) * (800 - margeHaute) }, CPoint{ xCourbe + 2.5f, ((100 - (TMin_Mois[i] + 50)) / 100) * (800 - margeHaute) });
                xCourbe += 2.5;
            }
            xCourbe = 60;

            for (size_t i = 1; i < TMax_Mois.size(); i++)
            {
                pLibgraph->setPen(MakeARGB(255, 255, 0, 0), 1.0f, LibGraph2::pen_DashStyles::Solid);
                pLibgraph->drawLine(CPoint{ xCourbe, ((100 - (TMax_Mois[i - 1] + 50)) / 100) * (800 - margeHaute) }, CPoint{ xCourbe + 2.5f, ((100 - (TMax_Mois[i] + 50)) / 100) * (800 - margeHaute) });
                xCourbe += 2.5;
            }
            xCourbe = 60;

            pLibgraph->endPaint();
            break;
        }
    }

    ReleaseLibGraph2();
    return 0;
}