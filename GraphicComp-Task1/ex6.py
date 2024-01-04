from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo a imagem e acrescentando ruído, e mostrando as duas imagens
img = io.imread('img/woman.png')

img_sp = util.random_noise(img, mode='s&p')

plt.figure(figsize=(30,10))
plt.subplot(1,2,1), plt.imshow(img), plt.title('Imagem Original'), plt.axis('off')
plt.subplot(1,2,2), plt.imshow(img_sp), plt.title('Imagem Original'), plt.axis('off')
plt.show()

# Aplicando filtros e mostrando as imagens resultantes

filtro = (1/9)*np.array([[1,1,1],[1,1,1],[1,1,1]])
img_sp=color.rgb2gray(img_sp[:,:,:3])
img_fmed = ndimage.convolve(img_sp,filtro)
img_fgauss = filters.gaussian(img_sp)
img_fmediana = filters.rank.median(img_sp,np.ones((3,3)))

plt.figure(figsize=(30,10))
plt.subplot(1,3,1), plt.imshow(img_fmed, cmap='gray'), plt.title('Filtro de Média'), plt.axis('off')
plt.subplot(1,3,2), plt.imshow(img_fgauss, cmap='gray'), plt.title('Filtro Gaussiano'), plt.axis('off')
plt.subplot(1,3,3), plt.imshow(img_fmediana, cmap='gray'), plt.title('Filtro de Mediana'), plt.axis('off')
plt.show()
