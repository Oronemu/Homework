import numpy as np

table = np.genfromtxt("/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/ABBREV.csv", delimiter=";", dtype=None, names=True, encoding="utf8")

max_kcal_name = table[np.argmax(table['Energ_Kcal'])]['Shrt_Desc']
print('1)', max_kcal_name)

max_sugar_name = table[np.argmax(table['Sugar_Tot_g'])]['Shrt_Desc']
print('2)', max_sugar_name)

max_protein_name = table[np.argmax(table['Protein_g'])]['Shrt_Desc']
print('3)', max_protein_name)

max_vit_c_name = table[np.argmax(table['Vit_C_mg'])]['Shrt_Desc']
print('4)', max_vit_c_name)