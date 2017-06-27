import requests, sys, os
import shutil
from bs4 import BeautifulSoup

CF_BASE_URL = 'http://www.codeforces.com'
PROBLEM_BASE_URL = 'http://www.codeforces.com/problemset/problem'
CONTEST_BASE_URL = ''

img_num = 1

def print_div(some_div):
	global img_num
	for elem in some_div.descendants:
		if elem.name == 'sub':
			elem.string = '_{'+str(elem.string)+'}'
		elif elem.name == 'sup':
			elem.string = '^{'+str(elem.string)+'}'
	for elem in some_div.descendants:
		if elem.name == 'p':
			print elem.text
			print
		if elem.name == 'img':
			r = requests.get(CF_BASE_URL+elem['src'], stream=True)
			filename = 'img'+str(img_num)
			with open(filename,'wb') as out_file:
				shutil.copyfileobj(r.raw, out_file)
			print '<Refer '+filename+'>'
			print
			del r
			img_num += 1


def print_problem_statement(problem_div):
	print_div(problem_div)

def print_input(input_specs_div):
	print_div(input_specs_div)

def print_output(output_specs_div):
	print_div(output_specs_div)

def print_note(note_div):
	print_div(note_div)

html = ''

if sys.argv[1] == '--problem' or sys.argv[1] == '-p':
	r = requests.get(PROBLEM_BASE_URL+'/'+sys.argv[2]+'/'+sys.argv[3])
	html = r.text
	del r
elif sys.argv[1] == '--contest' or sys.argv[1] == '-c':
	pass

soup = BeautifulSoup(html,'html.parser')
#print soup.find('div','problem-statement')
problem_statement_div = soup.find('div','problem-statement')
title = problem_statement_div.find('div','title').text
time_limit = problem_statement_div.find('div','time-limit').div.next_sibling
memory_limit = problem_statement_div.find('div','memory-limit').div.next_sibling
problem_div = problem_statement_div.find('div','input-specification').previous_sibling
input_specs_div = problem_statement_div.find('div','input-specification')
output_specs_div = problem_statement_div.find('div','output-specification')
examples_div = problem_statement_div.find('div','sample-tests')
note_div = problem_statement_div.find('div','note')

def get_examples(example_div):
	inputs = []
	outputs = []
	input_divs = example_div.find_all('div','input')
	output_divs = example_div.find_all('div','output')
	example_no = 1
	for input_div, output_div in zip(input_divs, output_divs):
		for br in input_div.find_all('br'):
			br.replace_with('\n')
		for br in output_div.find_all('br'):
			br.replace_with('\n')
		print 'Example #'+str(example_no)
		example_no += 1
		print input_div.pre.text
		inputs.append(input_div.pre.text)
		print output_div.pre.text
		outputs.append(output_div.pre.text)
		print
	return inputs, outputs

print 'Problem Title: '+title
print 'Time Limit Per Test: '+time_limit
print 'Memory Limit Per Test: '+memory_limit
print
print_problem_statement(problem_div)
print 'Input:'
print
print_input(input_specs_div)
print 'Output:'
print
print_output(output_specs_div)
inputs, outputs = get_examples(examples_div)
ex_no = 1
for i, o in zip(inputs, outputs):
	with open(str(ex_no)+'.in','w') as input_file:
		input_file.write(i)
	with open(str(ex_no)+'.out','w') as output_file:
		output_file.write(o)
	ex_no += 1
print 'Note:'
print_note(note_div)
