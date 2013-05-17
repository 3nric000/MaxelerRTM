X((params.ny) <= 10 && (params.ny) >= 1, "Stream offset param 'ny' must be between 1 and 10 (inclusive).")
X((params.nzy) <= 100 && (params.nzy) >= 1, "Stream offset param 'nzy' must be between 1 and 100 (inclusive).")
X((params.ny) <= 10 && (params.ny) >= 1, "Stream offset variable out of range ny{1..10}")
X((params.nzy) <= 100 && (params.nzy) >= 1, "Stream offset variable out of range nzy{ny{1..10}..10ny{1..10}}")
