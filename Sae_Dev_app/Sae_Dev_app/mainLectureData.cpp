

//
//#define NOMINMAX
//#include <Windows.h>
//#include <tchar.h>
//#include <chrono>
//#define LIBGRAPH2_LEVEL 4
//#include <LibGraph2.h>
//using namespace LibGraph2;
//
//#include <iostream>
//using namespace std;
//
//int APIENTRY _tWinMain(HINSTANCE hInstance,
//    HINSTANCE hPrevInstance,
//    LPTSTR    lpCmdLine,
//    int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    //Affiche la fenêtre graphique avec une taille par défaut
//    ILibGraph2* pLibgraph = GetLibGraph2();
//
//    // Taille fenetre
//    float size_width = 800;
//    float size_height = 800;
//
//    pLibgraph->show(CSize{ size_width, size_height });
//
//    //Boucle principale d'événements
//    evt e;
//    bool bShowDisk = true;
//    auto tpStartBounce = chrono::high_resolution_clock::now();
//    std::string strAnnee;
//
//    // VARIABLES POUR AFFICHER LES ANNEES EN DESSOUS DE LA COURBE
//    int annee = 1992;
//    float pointX = 20;
//    float pointY = size_width - 50;
//
//    float addPixelX = 50;
//    float addPixelY = size_height - 80;
//
//    while (pLibgraph->waitForEvent(e))
//    {
//        switch (e.type)  //En fonction du type du dernier événement
//        {
//        case evt_type::evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
//          //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
//            pLibgraph->beginPaint();
//
//
//
//
//
//            //Utiliser ici les fonctions de dessins
//            //Choisit un stylo rouge d'épaisseur 5 pixels traçant des pointillés
//            pLibgraph->setPen(MakeARGB(0, 0, 0, 0), 4.0f, LibGraph2::pen_DashStyles::Dash);
//            //Choisit un pinceau jaune
//            pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
//            //Dessine un rectangle avec le stylo et le pinceau sélectionné
//            pLibgraph->drawRectangle(CRectangle{ CPoint{50, 40}, CSize{5, size_height - 100} });
//            pLibgraph->drawRectangle(CRectangle{ CPoint{50, size_height - 62}, CSize{size_height - 100, 5} });
//            //Choisit un pinceau cyan translucide
//
//
//
//
//
//            pLibgraph->setPen(MakeARGB(255, 0, 0, 0), 5.0f, LibGraph2::pen_DashStyles::Solid);
//
//
//            strAnnee = to_string(1992);
//            pLibgraph->setFont(CString("Consolas"), 14, FontStyleRegular);
//
//            // Date début fin - Courbe X
//            pLibgraph->drawString("1992", CPoint{ 50, size_width - 50 });
//            pLibgraph->drawString("2021", CPoint{ size_width - 110, size_width - 50 });
//
//
//            // Température Min Max - Courbe Y
//            pLibgraph->drawString("-50°", CPoint{ 0, size_width - 80 });
//            pLibgraph->drawString("0°", CPoint{ 15, size_width / 2 - 40 });
//            pLibgraph->drawString("50°", CPoint{ 10, 40 });
//
//
//
//
//
//            // Tirets pour la courbe des dates
//            for (int i = 0; i < 138; ++i)
//            {
//                std::cout << addPixelX << std::endl;
//                pLibgraph->drawString("|", CPoint{ addPixelX, size_height - 80 });
//                addPixelX += 5;
//            }
//            addPixelX = 50;
//
//
//            // Tirets pour la courbe des dates
//            for (int i = 0; i < 138; ++i)
//            {
//                std::cout << addPixelY << std::endl;
//                pLibgraph->drawString("__", CPoint{ addPixelX, addPixelY - 20 });
//                addPixelY += 5;
//            }
//            addPixelY = 50;
//
//
//
//
//
//            // TEST
//            //pLibgraph->drawString("|", CPoint{ 50, size_width - 80 });
//
//
//
//            pLibgraph->endPaint();
//            break;
//
//        case evt_type::evtKeyDown:  //Enfoncement d'une touche
//            switch (e.vkKeyCode) //En fonction de la touche enfoncée
//            {
//            case 'H':
//                pLibgraph->hideConsole();
//                break;
//            case 'C':
//                pLibgraph->showConsole();
//                break;
//            }
//            break;
//
//        case evt_type::evtMouseDown:  //Déplacement de la souris
//            cout << "Clic de souris en position : " << e.x << ", " << e.y << endl;
//            bShowDisk = !bShowDisk;
//            pLibgraph->askForRefresh();
//            break;
//        }
//    }
//
//    ReleaseLibGraph2();
//    return 0;
//}