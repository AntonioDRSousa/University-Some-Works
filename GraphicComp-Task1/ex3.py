from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo a imagem e apresentando as imagens dos canais e respectivos histogramas

img = io.imread('img/leme.bmp')

img_ch0 = img[:,:,0]
img_ch1 = img[:,:,1]
img_ch2 = img[:,:,2]

img_ch0_flat = img_ch0.flatten()
img_ch1_flat = img_ch1.flatten()
img_ch2_flat = img_ch2.flatten()

# Plotando as imagens de cada canal em escala de cinza
plt.figure(figsize=(30,10))
plt.subplot(2,3,1), plt.imshow(img_ch0, cmap = 'gray'), plt.title('Canal R'), plt.axis('off')
plt.subplot(2,3,2), plt.imshow(img_ch1, cmap = 'gray'), plt.title('Canal G'), plt.axis('off')
plt.subplot(2,3,3), plt.imshow(img_ch2, cmap = 'gray'), plt.title('Canal B'), plt.axis('off')
plt.subplot(2,3,4), plt.hist(img_ch0_flat, bins=256)
plt.subplot(2,3,5), plt.hist(img_ch1_flat, bins=256)
plt.subplot(2,3,6), plt.hist(img_ch2_flat, bins=256)
plt.show()

# Aplicando a correção Gama sobre os canais e apresentando as imagens dos canais corrigidos e respectivos histogramas

img_ch0_gama = exposure.adjust_gamma(img_ch0, 0.5)
img_ch1_gama = exposure.adjust_gamma(img_ch1, 0.5)
img_ch2_gama = exposure.adjust_gamma(img_ch2, 0.5)

img_ch0_gama_flat = img_ch0_gama.flatten()
img_ch1_gama_flat = img_ch1_gama.flatten()
img_ch2_gama_flat = img_ch2_gama.flatten()

# Plotando as imagens de cada canal em escala de cinza
plt.figure(figsize=(30,10))
plt.subplot(2,3,1), plt.imshow(img_ch0_gama, cmap = 'gray'), plt.title('Canal R'), plt.axis('off')
plt.subplot(2,3,2), plt.imshow(img_ch1_gama, cmap = 'gray'), plt.title('Canal G'), plt.axis('off')
plt.subplot(2,3,3), plt.imshow(img_ch2_gama, cmap = 'gray'), plt.title('Canal B'), plt.axis('off')
plt.subplot(2,3,4), plt.hist(img_ch0_gama_flat, bins=256)
plt.subplot(2,3,5), plt.hist(img_ch1_gama_flat, bins=256)
plt.subplot(2,3,6), plt.hist(img_ch2_gama_flat, bins=256)
plt.show()

# Concatenando os negativos dos canais e apresentando a imagem colorida original e a negativa

img_gama = np.stack((img_ch0_gama,img_ch1_gama,img_ch2_gama), axis=-1)

plt.figure(figsize=(30,10))
plt.subplot(1,2,1), plt.imshow(img), plt.title('Imagem Original'), plt.axis('off')
plt.subplot(1,2,2), plt.imshow(img_gama), plt.title('Imagem Corrigida'), plt.axis('off')
plt.show()
