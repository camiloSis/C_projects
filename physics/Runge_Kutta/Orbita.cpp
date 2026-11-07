// Orbita de una particula bajo gravedad newtoniana, integrada con RK4.
// Unidades: GM = 1, distancia inicial = 1  ->  una orbita circular tiene periodo 2*pi.
// Salida: orbita.csv con columnas t,x,y,energia

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>

using Estado = std::array<double, 4>;  // {x, y, vx, vy}

constexpr double GM = 1.0;

// Derivada del estado: dx/dt = v, dv/dt = -GM * r / |r|^3
Estado derivada(const Estado& s) {
    const double r2 = s[0] * s[0] + s[1] * s[1];
    const double r3 = r2 * std::sqrt(r2);
    return {s[2], s[3], -GM * s[0] / r3, -GM * s[1] / r3};
}

// Un paso de Runge-Kutta de orden 4
Estado paso_rk4(const Estado& s, double dt) {
    auto suma = [](const Estado& a, const Estado& b, double k) {
        Estado c;
        for (int i = 0; i < 4; ++i) c[i] = a[i] + k * b[i];
        return c;
    };
    const Estado k1 = derivada(s);
    const Estado k2 = derivada(suma(s, k1, dt / 2));
    const Estado k3 = derivada(suma(s, k2, dt / 2));
    const Estado k4 = derivada(suma(s, k3, dt));

    Estado nuevo;
    for (int i = 0; i < 4; ++i)
        nuevo[i] = s[i] + dt / 6.0 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
    return nuevo;
}

// Energia por unidad de masa: debe conservarse (sirve para validar el codigo)
double energia(const Estado& s) {
    const double r = std::sqrt(s[0] * s[0] + s[1] * s[1]);
    return 0.5 * (s[2] * s[2] + s[3] * s[3]) - GM / r;
}

int main() {
    const double dt = 0.001;
    const double t_final = 20.0;  // ~3 orbitas

    // Velocidad menor que la circular (1.0) -> orbita eliptica
    Estado s = {1.0, 0.0, 0.0, 0.8};

    std::ofstream salida("orbita.csv");
    salida << "t,x,y,energia\n";

    const double E0 = energia(s);
    double error_max = 0.0;

    for (double t = 0.0; t <= t_final; t += dt) {
        salida << t << "," << s[0] << "," << s[1] << "," << energia(s) << "\n";
        error_max = std::fmax(error_max, std::fabs((energia(s) - E0) / E0));
        s = paso_rk4(s, dt);
    }

    std::cout << "Listo: orbita.csv generado.\n"
              << "Error relativo maximo de energia: " << error_max << "\n";
    return 0;
}