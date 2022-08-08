#! /bin/bash
get_xml_node_value()
{
  startline=$(grep -n "<$2" $1 | cut -d':' -f1)
  lastline=$(grep -n "<\/$2>" $1 | cut -d':' -f1)
  value=$(sed -n $startline,$lastline'p' $1)
  value=$(echo $value | sed -e "s/^.*<$3/<$3/" | sed -e "s/<$3>//g" | sed -e "s/<\/$3>//g" | awk -F"<" '{print $1}' | sed -e 's/[[:space:]]*$//' )
}
if [ $# -eq 3 ]; then
  if [ -f $1 ]; then
    get_xml_node_value $1 "$2" "$3"
    echo $value
  else
    echo "File $1 not found"
  fi
else
  echo "3 arguments are required: xml file name, section name, node name"
  echo "Example:"
  echo "./get_xml_node_value abc.xml \"Customer 1\" \"First name\""
fi

