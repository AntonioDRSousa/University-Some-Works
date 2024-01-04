from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo e apresentando a imagem colorida

img = io.imread('img/arara_full.png')
plt.figure(figsize=(10,10))
plt.imshow(img)
plt.axis('off')
plt.title('araras')
plt.show()

# Separando os canais e apresentando as imagens monocromáticas (de cada canal) e histogramas correspondentes

# Criando matrizes com cada canal da imagem
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

# Calculando os negativos dos canais e apresentando as imagens monocromáticas (de cada canal) e histogramas correspondentes

img_ch0_neg = 255 - img_ch0
img_ch1_neg = 255 - img_ch1
img_ch2_neg = 255 - img_ch2

img_ch0_neg_flat = img_ch0_neg.flatten()
img_ch1_neg_flat = img_ch1_neg.flatten()
img_ch2_neg_flat = img_ch2_neg.flatten()

plt.figure(figsize=(30,10))
plt.subplot(2,3,1), plt.imshow(img_ch0_neg, cmap = 'gray'), plt.title('Negativo do Canal R'), plt.axis('off')
plt.subplot(2,3,2), plt.imshow(img_ch1_neg, cmap = 'gray'), plt.title('Negativo do Canal G'), plt.axis('off')
plt.subplot(2,3,3), plt.imshow(img_ch2_neg, cmap = 'gray'), plt.title('Negativo do Canal B'), plt.axis('off')
plt.subplot(2,3,4), plt.hist(img_ch0_neg_flat, bins=256)
plt.subplot(2,3,5), plt.hist(img_ch1_neg_flat, bins=256)
plt.subplot(2,3,6), plt.hist(img_ch2_neg_flat, bins=256)
plt.show()

# Concatenando os negativos dos canais e apresentando a imagem colorida original e a negativa

img_neg = np.stack((img_ch0_neg,img_ch1_neg,img_ch2_neg), axis=-1)

plt.figure(figsize=(30,10))
plt.subplot(1,2,1), plt.imshow(img), plt.title('Imagem Original'), plt.axis('off')
plt.subplot(1,2,2), plt.imshow(img_neg), plt.title('Imagem Negativa'), plt.axis('off')
plt.show()
