from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo as imagens, pareando histogramas e apresentando as imagens originais e com histogramas pareados
from skimage import exposure

img1 = io.imread('img/tulipas.jpg')
img2 = io.imread('img/rosa_azul.jpg')

img1_h = exposure.match_histograms(img1,img2,channel_axis=-1)
img2_h = exposure.match_histograms(img2,img1,channel_axis=-1)

plt.figure(figsize=(30,10))
plt.subplot(2,2,1), plt.imshow(img1), plt.title('Imagem 1'), plt.axis('off')
plt.subplot(2,2,2), plt.imshow(img2), plt.title('Imagem 2'), plt.axis('off')
plt.subplot(2,2,3), plt.imshow(img2_h), plt.title('Imagem 2 com histograma da imagem 1'), plt.axis('off')
plt.subplot(2,2,4), plt.imshow(img1_h), plt.title('Imagem 1 com histograma da imagem 2'), plt.axis('off')
plt.show()
