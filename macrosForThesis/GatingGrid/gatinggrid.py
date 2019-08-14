"""
Created on Fri Mar  6 10:33:15 2015

Gating grid simulation

@author: tangwanc
"""
##################
from numpy import matrix
from numpy import linalg
from numpy import log
from numpy import arange
from numpy import arccos
from numpy import sin
from matplotlib import pyplot as plt
from math import pi
import numpy as np

# Electric field in [V/cm]
Ef = 133.3
# Electric field in [V/mm]
Efmm = Ef/10.0

# Electric Permativity [Farad/mm]
eps0 = 8.854187817e-15

# Heights of wire are referrenced from the pad plane (z = 0)

# Anode distance
z1 = 3.96

# Ground distance
z2 = 8.011

# Gating grid distance
z3 = 14.061

# Cathode distance
zp = 510.24

###### Pitch of wires ######

# Anode pitch
s1 = 4.0

# Ground pitch
s2 = 1.0

# Gating grid pitch
s3 = 1.0

###### Radii of wires ######

# Anode radius
rs = 0.01

# Ground radius
rz = 0.0381

# Gating grid radius
rg = 0.0381

###### Voltages [V]######

# Anode voltage
vs = 680

# Ground voltage
vz = 0

# Gating grid voltage
vg = -114.8

# Cathode voltage
vp = -6632.50

###### Matrices #######
A = (1/eps0)*matrix([[z1-(s1/(2*pi))*log(2*pi*rs/s1),z1,z1,z1],
                    [z1, z2-(s2/(2*pi))*log(2*pi*rz/s2), z2, z2],
                    [z1, z2, z3-(s3/(2*pi))*log(2*pi*rg/s3), z3],
                    [z1, z2, z3, zp]])

# Inverse of A
invA = linalg.inv(A)

# Voltage matrix
Vol = matrix([[vs], [vz], [vg], [vp]])

####### Solving for surface charge densities ######
sigma = invA*Vol

####### Solving for potential when cathode is not charged
Vp = (1/eps0)*(sigma[0,0]*z1+sigma[1,0]*z2+sigma[2,0]*z3)
Vinf = Vp
Vcath = -Efmm*(zp-z2)+Vinf

# z-z2
dz = arange(0,4,0.1)
Vz = -Efmm*dz + vz + (s2/(2*pi*eps0)*sigma[1,0]*log(2*pi*rz/s2))
#plt.plot(dz,Vz)
#plt.xlabel('z-z2 [mm]')
#plt.ylabel('V(z) [V]')
#plt.title('potential above ground grid')
#plt.grid(True)
#plt.show()

# V ground effective
vzeff = Vz[0]
print("V ground effective ", vzeff, "V")

# Calculate transparency (need only positive charge on the gating grid)
B = matrix([[z3-z2-(s3/(2*pi))*log(2*pi*rg/s3), -(z3-z2)],
            [-(z3-z2), zp-z2]])

K = eps0/((zp-z2)*(z3-z2-(s3/(2*pi))*log(2*pi*rg/s3)) -(z3-z2)**2)

Neg2Eeps = -2*Efmm*eps0
Pos2Eeps = 2*Efmm*eps0

Trans = []

for vgg in range(-150,40,1):
    DV = matrix([[vp-vzeff], [vgg-vzeff]])

    sigmaT = K*B*DV

    gate = sigmaT[1,0]*s3/(2*pi*rg)

    theta = arccos(-sigmaT[1,0]/(4*pi*eps0*Efmm*rg))

    sigmaPos = sigmaT[1,0]*theta/pi + 4*Efmm*eps0*rg*sin(theta)

    if gate < Neg2Eeps:
        Tr = 1.0
    elif gate > Pos2Eeps:
        Tr = 1- sigmaT[1,0]/abs(sigmaT[0,0])
    else:
        Tr = 1- sigmaPos/abs(sigmaT[0,0])

    if Tr < 0:
        Tr = 0
    ### keep value ###
    Trans.append(Tr)
# xgarf x data 
xgarf = [20,10,0,-10,-20,-30,-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76]
xdata = [-41.07,-56.23,-70.11,-83.1,-94.48,-103.27,-114.8,-124.38,-132.76,-142.54,-152.33]
#ydata ygarf
ydata = [.6778,.8042,.8664,.9159,.9507,.9727,1.001,1.008,1.014,.99926,.99926]
ygarf = [0,.124,.236,.374,.4845,.583,.7,.8185,.877,.9405,.9668,.9855,.996,1,1]
# plot transparency
vgg = arange(-150,40,1)
analytic,=plt.plot(vgg,Trans)
garfsim,=plt.plot(xgarf,ygarf,'g^')
expdata,=plt.plot(xdata,ydata,'rs')
plt.xlabel('Vg [V]')
plt.ylabel('Transparency')
plt.ylim(0,1.2)
plt.title('Transparency')
#plt.grid(True)
plt.legend([garfsim,expdata,analytic],["Garfield sim.","Exp. data","Analytic solution"])
plt.show()
for i in vgg:
     print i
