from dataclasses import asdict

import yaml
from model import CISBenchmark
import sys
from typing import List
from excel import parse_CIS_Excel

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: python {sys.argv[0]} <input_directory> <output_file>")
        sys.exit(1)

    input_directory = sys.argv[1]
    output_file = sys.argv[2]
    benchmarks = parse_CIS_Excel(input_directory)
    with open(output_file, 'w') as f:
        yaml.dump(asdict(benchmarks), f)
