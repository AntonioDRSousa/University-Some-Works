import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn import svm


wines = load_wine()
X_train, X_test, y_train, y_test = train_test_split(wines['data'], wines['target'], random_state = 42)


for i in range(13):
    for j in range((i+1),13):
        plt.scatter(wines['data'][:, i], wines['data'][:, j], c=wines['target'])
        plt.title('Wine recognition dataset')
        plt.xlabel(wines['feature_names'][i])
        plt.ylabel(wines['feature_names'][j])
        plt.plot()
        plt.savefig('graph'+str(i)+str(j)+'.png')

clf = svm.SVC(gamma = 0.001, kernel = "linear")
clf.fit(X_train, y_train)
pred = clf.predict(X_test)

accuracy = accuracy_score(y_test, pred)
print("precisao = "+str(accuracy * 100) )
