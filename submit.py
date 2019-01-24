import os

path= os.popen('pwd').readlines()
project_id = path[0][17:21]
os.system('~cs1010/submit-'+project_id)
