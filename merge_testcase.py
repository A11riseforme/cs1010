import os
import sys

project_id = str(sys.argv[1])
input_folder_name = "/home/y/yang-c/c/"+project_id+"-A11riseforme/inputs/"
output_folder_name = "/home/y/yang-c/c/"+project_id+"-A11riseforme/outputs/"
input_file = []
output_file = []

for filename in os.listdir(input_folder_name):
	input_file.append(filename)

for filename in os.listdir(output_folder_name):
	output_file.append(filename)

#print(input_file)
#print(output_file)

testio_file = "/home/y/yang-c/c/"+project_id+"-A11riseforme/testio.txt"

os.system("touch "+testio_file)

for i in range(len(input_file)):
    os.system("echo '" + input_file[i] + " inputs:' >>  " + testio_file)
    os.system("cat /home/y/yang-c/c/" + project_id + "-A11riseforme/inputs/" + input_file[i] + " >> " + testio_file)
    os.system("echo >>" + testio_file)
    os.system("echo '" + output_file[i] + " outputs:' >>  " + testio_file)
    os.system("cat /home/y/yang-c/c/" + project_id + "-A11riseforme/outputs/" + output_file[i] + " >> " + testio_file)
    os.system("echo '----------------------------------------------------------------' >> " + testio_file)
