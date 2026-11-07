import pandas as pd
import matplotlib.pyplot as plt

datos = pd.read_csv("orbita.csv")

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(11, 5))

# Trayectoria
ax1.plot(datos["x"], datos["y"], lw=1)
ax1.plot(0, 0, "yo", markersize=10, label="Cuerpo central")
ax1.set_aspect("equal")
ax1.set_xlabel("x")
ax1.set_ylabel("y")
ax1.set_title("Órbita")
ax1.legend()

# Conservación de energía (prueba de que el integrador funciona)
ax2.plot(datos["t"], datos["energia"])
ax2.set_xlabel("t")
ax2.set_ylabel("Energía")
ax2.set_title("Energía total (debe ser ~constante)")

plt.tight_layout()
plt.savefig("orbita.png", dpi=150)
print("Gráfica guardada en orbita.png")