import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <csv> <txt>")
        return

    # TODO: Read database file into a variable
    file = open(sys.argv[1], "r")
    people = []
    reader = csv.DictReader(file)
    for row in reader:
        people.append(row)
    file.close()
    # TODO: Read DNA sequence file into a variable
    file = open(sys.argv[2], "r")
    sequence = file.read()
    file.close()

    # TODO: Find longest match of each STR in DNA sequence
    profile = {}
    STRs = reader.fieldnames
    STRs.remove("name")
    for STR in STRs:
        num_match = longest_match(sequence, STR)
        profile[STR] = str(num_match)
    # TODO: Check database for matching profiles
    check = 0
    for person in people:
        for key in person:
            if key == "name":
                continue
            elif person[key] == profile[key]:
                check += 1
            else:
                check = 0
                break
        if check == len(profile):
            print(person["name"])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
