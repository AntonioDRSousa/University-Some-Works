from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo a imagem e transformando em monocromática, calculando gradiente e apresentando as imagens: original; monocromática; amplitude do gradiente; ângulo do gradiente

img = io.imread('img/brawn.bmp')
img_gray=color.rgb2gray(img)

gx = np.array([[-1,0,1],[-2,0,2],[-1,0,1]])
gy = np.array([[-1,-2,-1],[0,0,0],[1,2,1]])
img_gx = ndimage.convolve(img_gray,gx)
img_gy = ndimage.convolve(img_gray,gy)
g = abs(img_gx)+abs(img_gy)
g = g/np.amax(g)

ang = np.arctan2(img_gy,img_gx)
ang = ang/np.amax(ang)

plt.figure(figsize=(30,10))
plt.subplot(2,2,1), plt.imshow(img), plt.title('Imagem Original'), plt.axis('off')
plt.subplot(2,2,2), plt.imshow(img_gray, cmap='gray'), plt.title('Imagem Monocromatica'), plt.axis('off')
plt.subplot(2,2,3), plt.imshow(g, cmap='gray'), plt.title('Amplitude do Gradiente'), plt.axis('off')
plt.subplot(2,2,4), plt.imshow(ang, cmap='gray'), plt.title('Angulo do Gradiente'), plt.axis('off')

plt.show()
