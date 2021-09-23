#include <iostream>
#include "Messege.h"
#include "Epycycloid.h"

#include "gtest/gtest.h"
#include "tchar.h"

#include "pch.h"


TEST(EpycucloidConstructor, DefaultConstructor){
    class Epycycloid ep;
    ASSERT_EQ(2.0, ep.getRBig());
    ASSERT_EQ(1.0, ep.getRSmall());
    ASSERT_EQ(1.0, ep.getDist());
}

TEST(EpycucloidConstructor, InitConstructorWithDefault){
    class Epycycloid ep(3);
    ASSERT_EQ(3, ep.getRBig());
    ASSERT_EQ(1, ep.getRSmall());
    ASSERT_EQ(1, ep.getDist());
}

TEST(EpycucloidConstructor, InitConstructor){
    class Epycycloid ep(5, 4, 4);
    ASSERT_EQ(5, ep.getRBig());
    ASSERT_EQ(4, ep.getRSmall());
    ASSERT_EQ(4, ep.getDist());
}

TEST(EpycycloidConstructor, TestException){
    ASSERT_ANY_THROW(Epycycloid(1, 2, 5));
    ASSERT_ANY_THROW(Epycycloid(-1, 4, 4));
    ASSERT_ANY_THROW(Epycycloid(1, -4, 4));
    ASSERT_ANY_THROW(Epycycloid(1, 4, -4));
}

TEST(EpycycloidMethods, Setters){
    Epycycloid ep;

    ASSERT_ANY_THROW(ep.setRBig(1));
    ASSERT_ANY_THROW(ep.setRSmall(2.5));

    ep.setDist(3);
    ASSERT_EQ(3, ep.getDist());

    ep.setRBig(5);
    ASSERT_EQ(5, ep.getRBig());

    ep.setRSmall(3);
    ASSERT_EQ(3, ep.getRSmall());

    ASSERT_ANY_THROW(ep.setDist(-2));
    ASSERT_ANY_THROW(ep.setRBig(-2));
    ASSERT_ANY_THROW(ep.setRSmall(-2));

}

TEST(EpycycloidMethods, ParametersDefault){

    Epycycloid ep;

    ASSERT_NEAR(0, ep.sectorArea(0.5), eps);
    ASSERT_NEAR(0, ep.sectorArea(-1), eps);
    ASSERT_NEAR(0, ep.sectorArea(1), eps);
    ASSERT_EQ(Epycycloid::Types::SIMPLE, ep.type());

    ep.setDist(2);
    ASSERT_EQ(Epycycloid::Types::LONG, ep.type());

    ep.setDist(0.5);
    ASSERT_EQ(Epycycloid::Types::SHORT, ep.type());
}

TEST(EpycycloidMethods, Parameters){
    double rad1 = 3, rad2 = 2, dist = 2;
    Epycycloid ep(rad1, rad2, dist);
// change 0.00000001
    ASSERT_NEAR(0.0000001, ep.pointOfAngle(6.5).x, eps);
    ASSERT_NEAR(0.00000001, ep.pointOfAngle(-1).y, eps);

    ASSERT_NEAR(0.00000001, ep.curvRadiusOfAngle(1.5), eps);

    ASSERT_NEAR(0.00000001, ep.sectorArea(1.5), eps);
}

int _tmain(int argc, _TCHAR* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
