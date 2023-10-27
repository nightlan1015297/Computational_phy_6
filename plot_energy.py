import numpy as np
import matplotlib.pyplot as plt

eV = 1.60217662e-19
Bohr_radius = 5.29e-11
hbar = 1.054571817e-34
m_e = 9.1093837e-31
pi = 3.14159265359
nor = Bohr_radius / hbar * np.sqrt(m_e * eV)

V = -13.6 * eV / eV
a = 20 * Bohr_radius / Bohr_radius

def f_even(E):
    tmp1 = np.sqrt(-E)
    tmp2 = np.sqrt(E - V)
    tmp3 = a * np.sqrt(2 * (E - V))
    return tmp1 - tmp2 * np.tan(nor * tmp3)




def f_odd(E):
    tmp1 = np.sqrt(-E)
    tmp2 = np.sqrt(E - V)
    tmp3 = a * np.sqrt(2 * (E - V))
    return tmp1 + tmp2 / np.tan(nor * tmp3)



E = np.linspace(-13.59, 0, 1000)
plt.plot(E, f_even(E))
plt.plot(E, f_odd(E))
plt.ylim(-10, 10)
plt.show()

