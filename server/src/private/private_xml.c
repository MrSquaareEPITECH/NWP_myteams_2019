/*
** EPITECH PROJECT, 2020
** server
** File description:
** private_xml.c
*/

#include "private_xml.h"

#include <stdlib.h>
#include <string.h>

#include "util/string.h"
#include "xml/xml_attribute.h"

private_t *private_xml_import(xml_element_t *element)
{
    private_t *priv = malloc(sizeof(private_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    char *exchange = xml_attributes_get(element->attributes, "exchange");

    memset(priv->uuid, 0, sizeof(priv->uuid));
    strncpy(priv->uuid, uuid, UUID_LENGTH);
    memset(priv->exchange, 0, sizeof(priv->exchange));
    strncpy(priv->exchange, exchange, UUID_LENGTH);
    return (priv);
}

char *private_xml_export(private_t *priv)
{
    char *xml = strfmt("\t\t\t<private id=\"%s\" exchange=\"%s\"></private>",
        priv->uuid, priv->exchange);

    return (xml);
}
