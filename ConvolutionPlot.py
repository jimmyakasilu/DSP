import pylab as plt
with open("C:\Users\Siladittya\Desktop\ConvolvedData.txt",'r') as f:
    data = map(float,f.read().split())
    print(data)
    plt.stem(data)
    plt.xlim(-1,len(data)+1)
    plt.ylim(0,max(data)+1)
    plt.ylabel('Magnitude')
    plt.xlabel('Discrete TIme Intervals')
    plt.show()
    
