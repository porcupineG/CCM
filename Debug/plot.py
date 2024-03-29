#!/usr/bin/python
#-*- coding: utf-8 -*-

import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['font.family']='serif'
rcParams['text.usetex']=True
rcParams['text.latex.unicode']=True
rcParams['font.serif'] = 'Computer Modern Roman'
rcParams['text.latex.preamble']='\usepackage[T1]{fontenc}'

def plot(file, title, xlabel, ylabel):
    f = open(file, 'r')
    d = f.read().split('\n')[0:-1]
    y = [n.split(' ')[0] for n in d]
    x = [n.split(' ')[1] for n in d]
    plt.title(title, fontsize=16)
    plt.ylabel(xlabel, fontsize=16)
    plt.xlabel(ylabel, fontsize=16)
    plt.plot(x, y)
    f.close()

#f = open('y.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#print len(y)
#plt.plot(x, y)
#plt.show()
#f.close()
#
##f = open('fq.dat', 'r')
##y = [float(x) for x in f.read().split('\n')[0:-1]]
##x = np.arange(0, len(y), 1);
##print len(y)
##plt.plot(x, y)
##plt.show()
##f.close()
#
##f = open('qp.dat', 'r')
##y = [float(x) for x in f.read().split('\n')[0:-1]]
##x = np.arange(0, len(y), 1);
##print len(y)
##plt.plot(x, y)
##plt.show()
##f.close()
#
#f = open('fqn.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#f.close()
##plt.plot(x, y)
#
#
#f = open('x.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#f.close()
##plt.plot(x, y)
#
#f = open('fq.dat', 'r')
#y = [float(x) for x in f.read().split('\n')[0:-1]]
#x = np.arange(0, len(y), 1);
#f.close()
#plt.plot(x, y)
#
#plt.show()

#plot('fq.dat', ur'Częstotliwość chwilowa wygenerowanego sygnału', ur'Częstotliwość chwilowa [Hz]', ur'Czas [s]')
#plt.show()
#plot('s.dat', ur'Przebieg czasowy sygnału rzeczywistego', ur'Amplituda', ur'Czas [s]')
#plt.show()
#plot('n.dat', ur'Przebieg czasowy szumu', ur'Amplituda', ur'Czas [s]')
#plt.show()
plot('y.dat', ur'Przebieg czasowy sygnału wejściowego', ur'Amplituda', ur'Czas [s]')
plt.show()
plot('fq.dat', ur'Estymowana częstotliwość chwilowa', ur'Częstotliwosć [Hz]', ur'Czas [s]')
plot('x.dat', ur'Estymowana częstotliwość chwilowa', ur'Częstotliwosć [Hz]', ur'Czas [s]')
plt.show()


