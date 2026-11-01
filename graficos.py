import pandas as pd
import matplotlib.pyplot as plt

df_bubblesort = pd.read_csv('bubblesort.csv')
df_bubblesort_parada = pd.read_csv('bubblesort_parada.csv')
df_shell_sort = pd.read_csv('shell_sort.csv')
df_mergesort = pd.read_csv('mergesort.csv')
df_radixsort = pd.read_csv('radixsort.csv')


df_radixsort.plot(x='Tipo',y='Comparações',kind='bar',title='Radixsort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('radixsort_grafico.png', dpi=300, bbox_inches='tight')

df_bubblesort.plot(x='Tipo',y='Comparações',kind='bar',title='Bubblesort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('bubblesort_grafico.png', dpi=300, bbox_inches='tight')

df_bubblesort_parada.plot(x='Tipo',y='Comparações',kind='bar',title='Bubblesort com Parada',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('bubblesort_parada_grafico.png', dpi=300, bbox_inches='tight')

df_shell_sort.plot(x='Tipo',y='Comparações',kind='bar',title='Shellsort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('shell_sort_grafico.png', dpi=300, bbox_inches='tight')

df_mergesort.plot(x='Tipo',y='Comparações',kind='bar',title='Mergesort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('mergesort_grafico.png', dpi=300, bbox_inches='tight')

