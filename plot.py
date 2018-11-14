import sys
import scipy as sp
import matplotlib.pyplot


path = sys.argv[1]
data = sp.genfromtxt(path, delimiter=";", names=['x','y','z'])

matplotlib.pyplot.scatter(data['x'],data['y'],c=data['z'])
matplotlib.pyplot.show()

filename = path.split('.')
matplotlib.pyplot.savefig("{}_result.png".format(filename[0]))