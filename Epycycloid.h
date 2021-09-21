namespace Lab2 {
    const double eps = 10e-5;

    struct Point {
        double x;
        double y;
        Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
    };

    class Epycycloid {
    private:
        Point p;
        double r1, r2;
        double radBig, radSmall, distan;

    public:
        Epycycloid();

        Epycycloid(double rBig, double rSmall = 1.0, double dist = 1.0);

        //setters
        Epycycloid &setRBig(double r);

        Epycycloid &setRSmall(double r);

        Epycycloid &setDist(double dist);

        //getters
        double getRBig() const { return radBig; }

        double getRSmall() const { return radSmall; }

        double getDist() const { return distan; }

        //other methods
        Point pointOfAngle(double angle) const;

        double curvRadiusOfAngle(double angle) const;

        double sectorArea(double angle) const;

        enum class Types {
            SIMPLE,
            LONG,
            SHORT
        };
    };


        template<class T>
        int getNum(T &a) {
            std::cin >> a;
            if (!std::cin.good())
                return -1;
            return 1;
        }

}
