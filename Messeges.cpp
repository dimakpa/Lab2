#include <iostream>
#include "Messege.h"
#include "Epycycloid.h"
namespace Lab2 {
    int getNum(int &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    int dialog(const char *msgs[], int N) {
        const char *errmsg = "";
        int rc;
        int i, n;
        do {
            std::cout << errmsg << std::endl;
            errmsg = "You are wrong. Repeat, please!";

            std::cout << "Choose the number from alternatives:" << std::endl << std::endl;
            for (i = 0; i < N; ++i)
                std::cout << msgs[i] << std::endl;
            std::cout << std::endl;
            std::cout << "Make your choise -->" << std::endl;


            n = getNum(rc);
            if (n == -1)
                rc = 0;
        } while (rc < 0 || rc >= N);
        return rc;
    }

    void messege_start(Epycycloid *&ep) {
        int (*fptr[])(Epycycloid *&ep) = {nullptr,
                                          D_Add_Epycycloid,
                                          D_Set_Rad_Big,
                                          D_Set_Rad_Small,
                                          D_Set_Distance,
                                          D_Get_Rad_Big,
                                          D_Get_Rad_Small,
                                          D_Get_Distance,
                                          D_Point_Of_Angle,
                                          D_Get_Curve_rad,
                                          D_Type_Of_Epycycloid,
                                          D_Sectorial_Square,
        };

        const char *msgs[] = {"0. Quit",
                              "1. New Epycycloid",
                              "2. Show full info",
                              "3. Set big radius",
                              "4. Set small radius",
                              "5. Set distance",
                              "6. Get big radius",
                              "7. Get small radius",
                              "8. Get distance",
                              "9. Point of angle",
                              "10. Curve radius of angle",
                              "11. Sectorial area of angle",
                              "12. All parameters from pointsn9-11 of angle",
                              "13. Type of Epycycloid",
                              "14. Delete Epycycloid"};

        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

        int rc;
        while (rc = dialog(msgs, NMsgs)) {
            if (fptr[rc](ep) == -1)
                break;
        }


        printf("That's all, bye!");
    }

    int D_Add_Epycycloid(Epycycloid *&ep) {
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }
        try {
            ep = new Epycycloid;
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;


    }

    int D_Set_Rad_Big(Epycycloid *&ep) {
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        double rad1;
        std::cout << "Enter the big radius: ";
        status = getNum(rad1);

        if (status == -1)
            return -1;

        try {
            ep->setRBig(rad1);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
            }
        return 0;
    }

    int D_Set_Rad_Small(Epycycloid *&ep) {
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        double rad1;
        std::cout << "Enter the small radius: ";
        status = getNum(rad1);

        if (status == -1)
            return -1;

        try {
            ep->setRSmall(rad1);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;
    }

    int D_Set_Distance(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        double rad1;
        std::cout << "Enter the distance: ";
        status = getNum(rad1);

        if (status == -1)
            return -1;

        try {
            ep->setDist(rad1);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;
    }

    int D_Get_Rad_Big(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        std::cout << "Get the big radius: ";
        status = ep->getRBig();

        if (status == -1)
            return -1;

        try {
            ep->getRBig();
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        std::cout << ep->getRBig() << std::endl;
        return 0;
    }

    int D_Get_Rad_Small(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        std::cout << "Get the small radius: ";
        status = ep->getRSmall();

        if (status == -1)
            return -1;

        try {
            ep->getRSmall();
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        std::cout << ep->getRSmall() << std::endl;
        return 0;
    }

    int D_Get_Distance(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        std::cout << "Get the small radius: ";
        status = ep->getDist();

        if (status == -1)
            return -1;

        try {
            ep->getDist();
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }

        std::cout << ep->getDist() << std::endl;
        return 0;
    }

    int D_Point_Of_Angle(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        double angle;
        std::cout << "Set the angle: ";
        angle = getNum(status);

        status = ep->pointOfAngle(angle).x;

        if (status == -1)
            return -1;

        try {
            ep->pointOfAngle(angle);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }

        std::cout << "Point of angle:" << ep->pointOfAngle(angle).x << ep->pointOfAngle(angle).y << std::endl;
        return 0;

    }

    int D_Get_Curve_rad(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }
        int status;
        double angle;
        std::cout << "Set the angle: ";
        angle = getNum(status);

        status = ep->curvRadiusOfAngle(angle);

        if (status == -1)
            return -1;

        try {
            ep->curvRadiusOfAngle(angle);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        std::cout << "Curve angle: " << ep->curvRadiusOfAngle(angle) << std::endl;
        return 0;
    }

    //понять, как выбирать тип класса
    int D_Type_Of_Epycycloid(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        double rSmall = ep->getRSmall();
        double dist = ep->getDist();

        if (rSmall == dist){
            std::cout << "SIMPLE" << std::endl;
        } else if(rSmall > dist){
            std::cout << "SHORT" << std::endl;
        } else if (rSmall < dist){
            std::cout << "LONG" << std::endl;
        }


        try {
            ep->getRSmall();
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        return 0;
    }

    int D_Sectorial_Square(Epycycloid *&ep){
        if (ep == nullptr) {
            std::cout << "The Epycycloid is empty! Create new!" << std::endl;
            return 0;
        }

        int status;
        double angle;
        std::cout << "Set the angle: ";
        angle = getNum(status);

        status = ep->sectorArea(angle);

        if (status == -1)
            return -1;

        try {
            ep->sectorArea(angle);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "Epycycloid with this configuration doesn't exist! The previous epycycloid is saved!" << std::endl;
        }
        std::cout << "Sectorial square: " << ep->sectorArea(angle) << std::endl;


        return 0;
    }


}
