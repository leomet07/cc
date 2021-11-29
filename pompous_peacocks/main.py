def getUnbeatable(peacocks):
	realwinners = 0
	currentwinners = [] 
	exacts = []

	changedLast = 0
	for i in range(len(peacocks)):
		pck = peacocks[i]
		v , c  = pck

		if len(currentwinners) > 0:
			change = currentwinners
			
			for it in range(len(currentwinners)):
				w = currentwinners[it]
				print("NEW: ", change)
				
				isbiggerv = v > w[0]	
				isbiggerc = c > w[1]
				
				if (isbiggerv or isbiggerc) and not((isbiggerv and isbiggerc)):
					print("Beaten only one: ", w, pck)
					
					if v == w[0] or c == w[1]:
						print("RESET")
						change = []
						exacts = []
					change.append(pck)
					changedLast = i
					print("Changed last one:", changedLast)
					
				elif isbiggerc and isbiggerv:
					print("Beaten Both: ")
					change = []
					change.append(pck)
					exacts = []
					changedLast = i

					print("Changed last both: ", changedLast)
					
				elif v == w[0] and c == w[1]:
					if changedLast < i:
						print("--------------------Exact match", w, pck, changedLast, i)
						print(v , w[0], c , w[1])
						exacts.append(pck)

				print("END: ", change)
			currentwinners = change

		if i == 0:
			currentwinners.append(pck)

	print("end winners: ", currentwinners)
	print("end exacts", exacts)
	realwinners = len(currentwinners) + len(exacts)

	return realwinners

if __name__ == "__main__":
	

	# peacocks = [[1 ,3], [0 ,5]] # v ,c
	# peacocks = [[1 ,2], [1 , 4],] # v ,c
	# peacocks = [[1 ,3], [0 , 5], [1 , 5]] # v ,c
	# peacocks = [[3 ,4], [3, 4], [3 , 4]]
	# peacocks = [[1 ,3], [2, 3] ,  [ 2, 3 ] , [0 ,5]] # v ,c
	peacocks = [[1, 7] , [2, 7], [2, 6], [3,5], [3,5]]
	print("unbeatable peacocks: " , getUnbeatable(peacocks))
