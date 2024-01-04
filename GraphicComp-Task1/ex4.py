from skimage import io # leitura e escrita de imagens
from skimage import data # banco de imagens
from skimage import exposure # manipulação de contraste
from skimage import util # utilidades 
from skimage import filters # filtros
from skimage import color # conversão de cores
from scipy import ndimage # contém a operação de convolução (convolve) para a aplicação de filtros digitais
import matplotlib.pyplot as plt # visualização das imagens e histogramas
import numpy as np # operações matemáticas e matriciais

# Lendo a imagem 'moon', realizando o alargamento de contraste a equalização dos histogramas, e apresentando os histogramas
from skimage import exposure

img = data.moon()

pinf = np.percentile(img,2)
psup = np.percentile(img,98)

img_rescale = exposure.rescale_intensity(img,in_range=(pinf,psup))
img_eq = exposure.equalize_hist(img)

plt.figure(figsize=(30,10))
plt.subplot(2,3,1), plt.imshow(img, cmap='gray'), plt.title('Moon Original'), plt.axis('off')
plt.subplot(2,3,2), plt.imshow(img_rescale, cmap='gray'), plt.title('Alargamento de Contraste'), plt.axis('off')
plt.subplot(2,3,3), plt.imshow(img_eq, cmap='gray'), plt.title('Equalização de Histograma'), plt.axis('off')
plt.subplot(2,3,4), plt.hist(img.flatten(), bins=256)
plt.subplot(2,3,5), plt.hist(img_rescale.flatten(), bins=256)
plt.subplot(2,3,6), plt.hist(img_eq.flatten(), bins=256)
plt.show()

# Lendo a imagem 'camera', realizando o alargamento de contraste a equalização dos histogramas, e apresentando os histogramas
from skimage import exposure

img = data.camera()

pinf = np.percentile(img,2)
psup = np.percentile(img,98)

img_rescale = exposure.rescale_intensity(img,in_range=(pinf,psup))
img_eq = exposure.equalize_hist(img)

plt.figure(figsize=(30,10))
plt.subplot(2,3,1), plt.imshow(img, cmap='gray'), plt.title('Camera Original'), plt.axis('off')
plt.subplot(2,3,2), plt.imshow(img_rescale, cmap='gray'), plt.title('Alargamento de Contraste'), plt.axis('off')
plt.subplot(2,3,3), plt.imshow(img_eq, cmap='gray'), plt.title('Equalização de Histograma'), plt.axis('off')
plt.subplot(2,3,4), plt.hist(img.flatten(), bins=256)
plt.subplot(2,3,5), plt.hist(img_rescale.flatten(), bins=256)
plt.subplot(2,3,6), plt.hist(img_eq.flatten(), bins=256)
plt.show()
