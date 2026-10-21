import pandas as pd
import matplotlib.pyplot as plt
dict = {'Instancia':[10000,10000,10000,1000000,1000000,1000000],
        'Tipo':['Aleatorio','Ordenado Crescente','Ordenado Decrescente','Aleatorio','Ordenado Crescente','Ordenado Decrescente'],
        'Comparações':[4999500,4999500,4999500,None,None,None],
        'Trocas':[25038974,0,4999500,None,None,None],
        'Tempo de Execução':[0.193000,0.101000,0.226000,None,None,None]}

bolha = pd.DataFrame(dict)
bolha.to_csv('tabela.csv')

ticks = ['0.00s','0.05s','0.10s','0.15s','0.20s']
bolha.plot(y='Tempo de Execução',x = 'Instancia',kind='bar',xlabel='Instancia',ylabel='Tempo de Execução',title='Execução do Bubblesort',rot=45)
plt.yticks([0.00,0.05,0.10,0.15,0.20],ticks)
plt.savefig('bubblesort_grafico.png', dpi=300, bbox_inches='tight')
plt.show()
print(bolha)