import numpy as np
import matplotlib.pyplot as plt
import skimage

end_loop = False
centro_x = 0
centro_y = 0
scale = 1
vel = 0
ang = 0

# Função que gerencia eventos do mouse
def on_press(event):
    global centro_x, centro_y
    print('Você pressionou o botão do mouse:', event.button, event.xdata, event.ydata)
    centro_x = event.xdata
    centro_y = event.ydata
    
# Função que gerencia eventos do teclado
def on_key(event):
    global end_loop, scale, vel
    print('Você pressionou a tecla: "', event.key, '"', event.xdata, event.ydata)
    if event.key == 'q':
        end_loop = True
    elif event.key == 'up':
        scale = scale + 0.5
    elif event.key == 'down':
        scale = scale - 0.5
    elif event.key == 'right':
        vel = vel - 2
    elif event.key == 'left':
        vel = vel + 2

def animacao_objeto(obj):
    global end_loop, centro_x, centro_y, scale, vel, ang
    
    plt.close('all')            # Fecha todas as figuras abertas
    fig, ax = plt.subplots()    # Instancia objetos: figura e eixos correspondentes
    ax.cla()                    # Limpa figura/eixos

    # Conecta call backs associados aos eventos (mouse e teclado)
    cid = fig.canvas.mpl_connect('button_press_event', on_press)
    cid = fig.canvas.mpl_connect('key_press_event', on_key)

    # Pontos do objeto
    po = np.transpose(obj)

    # O loop acaba quando a tecla "q" é pressionada

    c = 0

    while not end_loop:
        # Propriedades dos eixos da figura
        ax.cla()
        ax.set_xlim([-7,7]), ax.set_ylim([-7,7])
        ax.set_aspect(1)
        plt.axhline(linewidth=1), plt.axvline(linewidth=1)

        # angulo
        ang += vel
        rad_ang = (ang/180)*np.pi

        # transformacoes afins
        Tt1 = np.array([[1,0,-centro_x],[0,1,-centro_y],[0,0,1]])
        Tt2 = np.array([[1,0,centro_x],[0,1,centro_y],[0,0,1]])
        Ts = np.array([[scale,0,0],[0,scale,0],[0,0,1]])
        R = np.array([[np.cos(rad_ang),-np.sin(rad_ang),0],[np.sin(rad_ang),np.cos(rad_ang),0],[0,0,1]])

        T  = np.matmul(Tt2,Ts)
        pT = np.matmul(T, po)
        
        T = np.matmul(R, Tt1)
        T = np.matmul(Tt2, T)
        pT = np.matmul(T, pT)

        # desenha o objeto geometrico
        plt.fill(pT[0,:], pT[1,:], facecolor=skimage.color.hsv2rgb((c,1,1)))

        c= (c+0.01) % 1
        
        plt.pause(0.01)


## programa principal ##
        
p = np.array([[-0.5,-0.5,1],[0.5,-0.5,1],[0.5,0.5,1],[-0.5,0.5,1]]) # quadrado unitario centrado na origem
animacao_objeto(p)
    
    


