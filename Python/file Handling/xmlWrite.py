#
# Generate a valid xml file at /tmp/vulnerable-countries.xml.
# It should contain a list of country nodes attached to a root node
# that have name attributes, the third node should be Panama.
#


import xml.etree.cElementTree as ET


#root = ET.Element("root")
#ET.SubElement(root, "country", name="Malawi")
#ET.SubElement(root, "country", name="USA")
#ET.SubElement(root, "country", name="Panama")


import xml.etree.cElementTree as ET

root = ET.Element("root")
doc = ET.SubElement(root, "doc")

ET.SubElement(doc, "field1", name="blah").text = "some value1"
ET.SubElement(doc, "field2", name="asdfasd").text = "some vlaue2"

tree = ET.ElementTree(root)
tree.write("/Users/HarryOB/Desktop/file.xml")
