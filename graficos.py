import pandas as pd
import matplotlib.pyplot as plt

df_bubblesort = pd.read_csv('bubblesort.csv')
df_bubblesort_parada = pd.read_csv('bubblesort_parada.csv')
df_shell_sort = pd.read_csv('shell_sort.csv')
df_mergesort = pd.read_csv('mergesort.csv')
df_radixsort = pd.read_csv('radixsort.csv')
df_binary_insertion_sort = pd.read_csv('binary_insertion_sort.csv')
df_heapsort = pd.read_csv('heapsort.csv')
df_insertion_sort = pd.read_csv('insertion_sort.csv')
df_selection_sort = pd.read_csv('selection_sort.csv')
df_ternary_insertion_sort = pd.read_csv('ternary_insertion_sort.csv')
df_quicksort = pd.read_csv('quicksort.csv')
df_bucketsort = pd.read_csv('bucketsort.csv')


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

df_binary_insertion_sort.plot(x='Tipo',y='Comparações',kind='bar',title='Binary Insertion Sort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('binary_insertion_sort_grafico.png', dpi=300, bbox_inches='tight')

df_heapsort.plot(x='Tipo',y='Comparações',kind='bar',title='Heapsort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('heapsort_grafico.png', dpi=300, bbox_inches='tight')

df_insertion_sort.plot(x='Tipo',y='Comparações',kind='bar',title='Insertion Sort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('insertion_sort_grafico.png', dpi=300, bbox_inches='tight')

df_selection_sort.plot(x='Tipo',y='Comparações',kind='bar',title='Selection Sort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('selection_sort_grafico.png', dpi=300, bbox_inches='tight')

df_ternary_insertion_sort.plot(x='Tipo',y='Comparações',kind='bar',title='Ternary Insertion Sort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('ternary_insertion_sort_grafico.png', dpi=300, bbox_inches='tight')

df_quicksort.plot(x='Tipo',y='Comparações',kind='bar',title='Quicksort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('quicksort_grafico.png', dpi=300, bbox_inches='tight')

df_bucketsort.plot(x='Tipo',y='Comparações',kind='bar',title='Bucket Sort',xlabel='Instancia',ylabel='Comparações',logy=True,rot = 45)
plt.savefig('bucketsort_grafico.png', dpi=300, bbox_inches='tight')


